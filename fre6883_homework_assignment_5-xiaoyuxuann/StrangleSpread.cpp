#include "StrangleSpread.h"
#include <iostream>
#include <cmath>
using namespace std;
namespace fre {
    double StrangleSpread::Payoff(double z) const 
    { 
        if(z>K2){
            return z-K2;
        }
        if(z<=K1){
            return K1-z;
        }
        return 0.0;
    }
}