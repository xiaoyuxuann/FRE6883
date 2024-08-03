#include "CouponBond.h" 
#include <cmath> 
namespace fre {
    double CouponBond::Price(double y)
    {
        double sum = 0;
        for(int n=1;n<=T;n++){
            sum += C * exp(-y * n);
        }
        return sum + F * exp(-y * T);
    }
    
    double CouponBond::Vega(double y)
    {
        double sum = 0;
        for(int n=1;n<=T;n++){
            sum += -C * n * exp(-y * n);
        }
        return sum - F * T* exp(-y * T);
    }
    
    double Intermediary::Value(double y)
    {
        return Price(y);
    }
    double Intermediary::Deriv(double y)
    {
        return Vega(y);
    }
}