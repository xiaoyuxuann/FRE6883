#include "Option01.h"
#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace fre {
    double Factorial(int n)
    {
        double num = 1.0;
        if (n <= 0)
            return num;
        
        do {
            num = num * n;
            n--;
        }while (n > 0);
        return num;
    }
    
    double PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K)
    {
        double q = RiskNeutProb(U, D, R);
        double sum = 0.0;
        for (unsigned int i = 0; i <= N; i++)
        {
            sum += Factorial(N) / (Factorial(i) * Factorial(N - i)) * pow(q,i) * pow(1 - q,N - i) * CallPayoff(CalculateAssetPrice(S0, U, D, N, i), K);
        }
        return 1 / pow(R,N) * sum;
    }

    double CallPayoff(double z, double K)
    {
        if (z > K) return z - K;
        return 0.0;
    }
}