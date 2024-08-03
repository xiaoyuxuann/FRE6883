#include <iostream>
#include <cmath>
#include "Option05.h"
#include "BinomialTreeModel.h"
using namespace std;
namespace fre{
    class ButterflySpread: public EurOption{
        private:
            double K1;
            double K2;
        public:
            ButterflySpread(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
            ~ButterflySpread() {}
            double Payoff(double z) const;
    };
}