#include <iostream>
#include <cmath>
#include "Option05.h"
#include "BinomialTreeModel.h"
using namespace std;
namespace fre{
    class StrangleSpread: public EurOption{
        private:
            double K1;
            double K2;
        public:
            StrangleSpread(int N_, double K1_, double K2_) : EurOption(N_), K1(K1_), K2(K2_) {}
            ~StrangleSpread() {}
            double Payoff(double z) const;
    };
}