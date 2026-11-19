#include <iostream>

#include "bk/trapezoid.h"
#include "bk/function.h"

trapezoid::trapezoid(Function &f, double a, double b, int N) : func(f)
{
        Iin = a;
        Ifin = b;
        divisions = N;
}

trapezoid::trapezoid(const trapezoid &obj) : func(obj.func)
{
        std::cout << "Copy constructor invoked!" << std::endl;

        Iin = obj.Iin;
        Ifin = obj.Ifin;
        divisions = obj.divisions;
}

double trapezoid::integrate(){
        double h = (double)((Ifin - Iin) / divisions);

        double s = 0.0;
	for (int k = 1; k < divisions; ++k)
		s += func.evaluate(Iin + k * h);
        return h * (0.5 * func.evaluate(Iin) + 0.5 * func.evaluate(Ifin) + s);
}

double trapezoid::integrate(const std::vector<double> &f, double h){
        int n = f.size();

        double s = 0.0;
        for (int k = 1; k < n - 1; ++k)
                s += f[k];
        return h * (0.5 * f[0] + 0.5 * f[n - 1] + s);
}
