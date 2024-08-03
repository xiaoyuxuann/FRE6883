#include "BinomialTreeModel.h"
#include "Option08.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using namespace fre;
int main()
{ 
    int N=8;
    double r = 0.058, sigma = 0.46, T=(double)9/12; 
    double S0 = 106.00, K = 100.00; 
    cout << setiosflags(ios::fixed) << setprecision(5);
    
    double h = T / N;
    double U = exp(sigma * sqrt(h));
    double D = 1 / U;
    double R = exp(r * h);
    BinomialTreeModel Model(S0, U, D, R);
    
    cout << "SO = " << S0 << endl;
    cout << "r = " << r << endl;
    cout << "sigma = " << sigma << endl;
    cout << "T = " << T << endl;
    cout << "K = " << K << endl;
    cout << "N = " << N << endl;
    cout << "U = " << U << endl;
    cout << "D = " << D << endl;
    cout << "R = " << R << endl;
    
    Call call(N,K);
    OptionCalculation callCalculation(&call);
    cout << "American call option price = " << fixed << setprecision(3) << callCalculation.PriceBySnell(Model) << endl;
    return 0;
}
/*
Output:
SO = 106.00000
r = 0.05800
sigma = 0.46000
T = 0.75000
K = 100.00000
N = 8
U = 1.15125
D = 0.86862
R = 1.00545
American call option price = 21.682
*/