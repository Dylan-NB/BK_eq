#ifndef RUNGEKUTTA2_H
#define RUNGEKUTTA2_H

#include <vector>
#include "function.h"

class RungeKutta2
{
	public:
		RungeKutta2(Function &f, double x0, double y0, double x, double h);
		RungeKutta2(const RungeKutta2 &obj);
		double xin;
		double yin;
		double xTarget;
		double step;
		double method();
		std::vector<double> xValues;
    		std::vector<double> yValues;
	private:
		Function &func;
		RungeKutta2();
};
#endif 
