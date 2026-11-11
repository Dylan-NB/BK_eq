#ifndef RUNGEKUTTA4_H
#define RUNGEKUTTA4_H

#include <vector>
#include "function.h"

class RungeKutta4
{
	public:
		RungeKutta4(Function &f, double x0, double y0, double x, double h);
		RungeKutta4(const RungeKutta4 &obj);
		double xin;
		double yin;
		double xTarget;
		double step;
		double method();
		std::vector<double> xValues;
    		std::vector<double> yValues;
	private:
		Function &func;
		RungeKutta4();
};
#endif 
