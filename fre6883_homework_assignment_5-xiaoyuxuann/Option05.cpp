#include <iostream>
#include <cmath>
#include "Option05.h"
#include "BinomialTreeModel.h"
#include "DoubDigitOpt.h"
#include "StrangleSpread.h"
#include "ButterflySpread.h"
using namespace std;
namespace fre {
    EurOption::~EurOption() {}
    double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model)
    { 
        double optionPrice=0.0;
        double q = Model.RiskNeutProb();
        int N = pOption->GetN();
        double* pPrice = new double[N + 1];
        for(int i=0;i<=N;i++)
        { 
            pPrice[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i)); 
        }
        for(int n=N-1;n>=0;n--)
        { 
            for(int i=0;i<=n;i++)
            { 
                pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();
            }
        }
        optionPrice = pPrice[0];
        delete[] pPrice;
        pPrice = nullptr;
        return optionPrice;
    }
}