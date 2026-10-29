#include <iostream>
#include <cmath>

#include "bk/function.h"

Function::Function(){}

Function::~Function(){}

double Function::evaluate(double x, double y){
	return x + y;
}
