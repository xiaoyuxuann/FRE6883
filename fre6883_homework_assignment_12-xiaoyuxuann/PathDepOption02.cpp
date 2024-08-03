#include "PathDepOption02.h"
#include "Matrix.h"
#include <cmath>
#include <iostream>

namespace fre {
    
    double PathDepOption::PriceByMC(MCModel& Model, long N, double epsilon)
    {
        double H = 0.0;
        SamplePath S(m);
        int d = Model.GetS0().size();
        Vector Heps(d);
        Vector vepsilon(d);
        for (int i = 0; i < d; i++) vepsilon[i] = 1.0;

        for (long i = 0; i < N; i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H = (i * H + Payoff(S)) / (i + 1.0);
            for (int j = 0; j < d; j++)
            {
                Matrix rescaledS(m);
                vepsilon[j] = vepsilon[j] + epsilon;
                for (int l=0;l<m;l++)
                {
                    rescaledS[l]=vepsilon*S[l];
                }
                vepsilon[j] = vepsilon[j] - epsilon;
                Heps[j] = (i * Heps[j] + Payoff(rescaledS)) / (i + 1.0);
            }
        }
        Price = std::exp(-Model.GetR() * T) * H;
        delta = std::exp(-Model.GetR() * T) * (-H + Heps) / (epsilon * Model.GetS0());
        return Price;
    }
    
    double ArthmAsianCall::Payoff(const SamplePath& S) const
    {
        double Ave = 0.0;
        int d = S[0].size();
        Vector one(d);
        for (int i = 0; i < d; i++) one[i] = 1.0;
        for (int k = 0; k < m; k++)
        {
            Ave = (k * Ave + (one ^ S[k])) / (k + 1.0);
        }
        if (Ave < K) return 0.0;
        return Ave - K;
    }
}
