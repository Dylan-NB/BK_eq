#include <iostream>
#include <vector>

#include "RungeKutta2.h"
#include "function.h"

RungeKutta2::RungeKutta2(Function &f, double x0, double y0, double x, double h) : func(f)
{
	xin = x0;
	yin = y0;
	xTarget = x;
	step = h;
}

RungeKutta2::RungeKutta2(const RungeKutta2 &obj) : func(obj.func)
{
	std::cout << "Copy constructor invoked!" << std::endl;
	
	xin = obj.xin;
	yin = obj.yin;
	xTarget = obj.xTarget;
	step = obj.step;
	xValues = obj.xValues;
	yValues = obj.yValues;
}

double RungeKutta2::method(){
	int n = (int)((xTarget - xin) / step);

	double x = xin;
	double y = yin;

	xValues.push_back(x);
	yValues.push_back(y);

	for(int i = 1; i <= n; ++i){
		double k1 = step * func.evaluate(x, y);
		double k2 = step * func.evaluate(x + 0.5 * step, y + 0.5 * k1);

		y = y + k2;
		x = x + step;

		xValues.push_back(x);
		yValues.push_back(y);
	}
	return y;
}
