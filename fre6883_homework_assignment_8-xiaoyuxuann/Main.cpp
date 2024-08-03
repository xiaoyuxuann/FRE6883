#include <iostream>
#include <iomanip>
#include "Function.h" 
#include "NonlinearSolver02.h" 
#include "CouponBond.h"
using namespace std;
using namespace fre;
int main()
{
    double F=100.0;
    double T=3.0;
    double C=1.2;
    double P=98.56;

    double Acc=0.0001;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
    
    NonlinearSolver02 solver(P, LEnd, REnd, Acc, Guess); 
    Intermediary bond(F, T, C, P);
    cout << "Yield by bisection method: " << fixed << setprecision(4) << solver.SolveByBisect(&bond) << endl;
    cout << "Yield by Newton-Raphson method: " << fixed << setprecision(4) << solver.SolveByNR(&bond) << endl;
}
/* outcome:
Yield by bisection method: 0.0168
Yield by Newton-Raphson method: 0.0168
*/