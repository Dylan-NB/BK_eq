#include <iostream>
#include <cmath>

#include "bk/function.h"

Function::Function(){}

Function::~Function(){}

double Function::evaluate(double x, double y){
	return y * y * std::sin(x);
}

double Function::N0(double r){
	return 1 - std::exp(-r * r * Qs0 / 4.0);   //ec. 4.53
}

double Function::evaluate(double rp){
	if (rp <= 0.0 || std::fabs(rp - r) < 1e-12)    
                return 0.0;	
	double r2 = std::fabs(r - rp);
	double bracket = N0(rp) + N0(r2) - N0(r) - N0(rp) * N0(r2);
	double K = (r * r)/((rp * rp) * (r2 * r2));
 	return 2.0 * M_PI * rp * K * bracket; 
}
