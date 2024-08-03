#include <iostream>
#include <iomanip>
#include "BinomialTreeModel.h"
#include "Option05.h"
#include "DoubDigitOpt.h"
#include "ButterflySpread.h"
#include "StrangleSpread.h"
using namespace std;
using namespace fre;
int main()
{ 
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545; 
    double S0 = 106.00, K1 = 100, K2 = 110; 
    BinomialTreeModel Model(S0, U, D, R);
    DoubDigitOpt doubDigitOpt(N, K1, K2);
    OptionCalculation optCalculation(&doubDigitOpt); 
    cout << "European double digit option price = " << fixed << setprecision(2) << optCalculation.PriceByCRR(Model) << endl;
    StrangleSpread stranglespread(N, K1, K2);
    OptionCalculation strangleCalculation(&stranglespread);
    cout << "European strangle option price = " << fixed << setprecision(2) << strangleCalculation.PriceByCRR(Model) << endl;
    ButterflySpread butterflyspread(N, K1, K2);
    OptionCalculation butterflyCalculation(&butterflyspread);
    cout << "European butterfly option price = " << fixed << setprecision(2) << butterflyCalculation.PriceByCRR(Model) << endl;
    return 0;
}
/*
European strangle option price = 28.39
European butterfly option price = 1.04
*/