#include <iostream>
#include <vector>

#include "bk/RungeKutta4.h"
#include "bk/function.h"

RungeKutta4::RungeKutta4(Function &f, double x0, double y0, double x, double h) : func(f)
{
	xin = x0;
	yin = y0;
	xTarget = x;
	step = h;
}

RungeKutta4::RungeKutta4(const RungeKutta4 &obj) : func(obj.func)
{
	std::cout << "Copy constructor invoked!" << std::endl;
	
	xin = obj.xin;
	yin = obj.yin;
	xTarget = obj.xTarget;
	step = obj.step;
	xValues = obj.xValues;
	yValues = obj.yValues;
}

double RungeKutta4::method(){
	int n = (int)((xTarget - xin) / step);

	double x = xin;
	double y = yin;

	xValues.clear();
	yValues.clear();
	xValues.push_back(x);
	yValues.push_back(y);

	for (int i = 1; i <= n; ++i) {
    		double k1 = step * func.evaluate(x,              y);
    		double k2 = step * func.evaluate(x + 0.5 * step, y + 0.5 * k1);
    		double k3 = step * func.evaluate(x + 0.5 * step, y + 0.5 * k2);
    		double k4 = step * func.evaluate(x + step,       y + k3);

    		y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    		x = x + step;

    		xValues.push_back(x);
    		yValues.push_back(y);
		}
	return y;
}

void RungeKutta4::stepDipole(Dipole &dip, double dy, double abar){ // h = dy
        int n = dip.N.size();
        Dipole mid = dip;

        std::vector<double> k1 = rhs(dip, abar);

        for (int j = 0; j < n; ++j) {
                mid.N[j] = dip.N[j] + 0.5 * dy * k1[j];
        }
        std::vector<double> k2 = rhs(mid, abar);

        for (int j = 0; j < n; ++j) {
                mid.N[j] = dip.N[j] + 0.5 * dy * k2[j];
        }
        std::vector<double> k3 = rhs(mid, abar);

        for (int j = 0; j < n; ++j) {
                mid.N[j] = dip.N[j] + dy * k3[j];
        }
        std::vector<double> k4 = rhs(mid, abar);

        for (int j = 0; j < n; ++j) {
                double pendiente = (k1[j] + 2.0 * k2[j] + 2.0 * k3[j] + k4[j]) / 6.0;
                dip.N[j] = dip.N[j] + dy * pendiente;
        }

        dip.y = dip.y + dy;
}
