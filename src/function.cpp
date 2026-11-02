#include <iostream>
#include <cmath>

#include "function.h"

Function::Function(){}

Function::~Function(){}

double Function::evaluate(double x, double y){
	return y * y * std::sin(x);
}
