#include <iostream>
#include <cmath>

#include "bk/function.h"

Function::Function(){}

Function::~Function(){}

double Function::evaluate(double x, double y){
	return y * y * std::sin(x);
}

double Function::evaluate(double x){
        return std::exp(x);
}
