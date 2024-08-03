#include <iostream>
#include <cmath>
#include "Option08.h"
#include "BinomialTreeModel02.h"
#include "BinLattice02.h"
using namespace std;
namespace fre {
    Option::~Option() {}
    double Call::Payoff(double z) const
    { 
        if(z>K) return z-K;
        return 0.0; 
    }
    double Put::Payoff(double z) const 
    { 
        if(z<K) return K-z;
        return 0.0;
    }
    double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model, BinLattice02<double>& price, BinLattice02<double>& stock, BinLattice02<double>& position)
    { 
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        price.SetN(N);
        stock.SetN(N);
        position.SetN(N);
        for(int i=0;i<=N;i++)
        { 
            price.SetNode(N,i,pOption->Payoff(Model.CalculateAssetPrice(N,i)));
            stock.SetNode(N,i,0);
            position.SetNode(N,i,0);
        }
        for(int n=N-1;n>=0;n--)
        { 
            for(int i=0;i<=n;i++)
            { 
                price.SetNode(n,i,(q*price.GetNode(n+1,i+1)+(1-q)*price.GetNode(n+1,i))/Model.GetR());
                stock.SetNode(n,i,(price.GetNode(n+1,i+1)-price.GetNode(n+1,i))/(Model.CalculateAssetPrice(n+1,i+1)-Model.CalculateAssetPrice(n+1,i)));
                position.SetNode(n,i,(price.GetNode(n+1,i)-stock.GetNode(n,i)*Model.CalculateAssetPrice(n+1,i))/Model.GetR());
            }
        }
        return price.GetNode(0,0);
    }
}