#pragma once
#include "NonlinearSolver02.h" 
namespace fre {
    class CouponBond {
        private:
            double F;
            double T;
            double C;
            double P;
        public:
            CouponBond(double F_, double T_, double C_, double P_) :F(F_), T(T_), C(C_), P(P_) { }
            double Price(double y); 
            double Vega(double y);
    };
    
    class Intermediary : public CouponBond, public Function{
        public:
            Intermediary(double F_, double T_, double C_, double P_) : CouponBond(F_, T_, C_, P_) { }
            double Value(double y);
            double Deriv(double y); 
    };
}