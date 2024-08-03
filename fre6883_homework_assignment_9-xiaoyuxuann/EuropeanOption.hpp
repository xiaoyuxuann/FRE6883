#include <iostream>
// EuropeanOption2.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only. It has been 
// written for pedagogical reasons
//
// (C) Datasim Component Technology BV 2003-2006
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
using namespace std;

class EuropeanOption
{
private:
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double U;		// Current underlying price (e.g. stock, forward)
	double b;		// Cost of carry

	char c = 'C';
	char* optType;	// Option name (call, put)
	// Name of underlying asset
	
	// Gaussian functions
	double n(double x) const;
	double N(double x) const;

public:				// For TEST purposes only
	// 'Kernel' functions for option calculations
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
	double CallGamma() const;
	double PutGamma() const;
	double CallVega() const;
	double PutVega() const;

public:	// Public functions
	EuropeanOption(): r(0.08), sig(0.3), K(65.0), T(0.25), U(60.0), b(r) { optType = &c; };							// Default call option
	EuropeanOption(double r_, double sig_, double K_, double T_, double U_, double b_, char* optType_): r(r_), sig(sig_), K(K_), T(T_), U(U_), b(b_), optType(optType_) {};
	EuropeanOption(const EuropeanOption& option2): r(option2.r), sig(option2.sig), K(option2.K), T(option2.T), U(option2.U), b(option2.b), optType(option2.optType) {};	// Copy constructor
	EuropeanOption (const char* optionType);	// Create option type
	virtual ~EuropeanOption();	

	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)


};

#endif
