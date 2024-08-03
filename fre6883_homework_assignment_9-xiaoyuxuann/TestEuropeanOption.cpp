// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <cmath>

int main()
{
	// Call option on a stock
	EuropeanOption callOption;
	cout << "Call option on a stock: " << callOption.Price() << endl;
	//cout << "Delta on a call option: " << callOption.Delta() << endl;

	// Put option on a stock index
	char* optType = new char;
	*optType = 'P';
	double U = 100.0, K = 95.0, T = 0.5, r = 0.10, sig = 0.20;
	double q = 0.05;		// Dividend yield
	double b = r - q;
	EuropeanOption indexOption(r, sig, K, T, U, b, optType);

	//cout << "Put option on an index: " << indexOption.Price() << endl;
	//cout << "Delta on a put option: " << indexOption.Delta() << endl;
	
	U = 50.0, K = 50.0, T = 0.25, r = 0.10, sig = 0.30, b = 0.10;
	EuropeanOption putOption(r, sig, K, T, U, b, optType);
	cout << "Put option on a stock: " << putOption.Price() << endl;
	
	U = U - 1.5 * exp(-r * 0.1667);
	EuropeanOption DividendputOption(r, sig, K, T, U, b, optType);
	cout << "Put option with dividend: " << DividendputOption.Price() << endl;
	
	delete optType;

	return 0;
}
/*
Q1: Call option on a stock: 2.13293
Q2: Put option on a stock: 2.37561
Q3: Put option with dividend: 3.03039
*/
