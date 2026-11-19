#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "function.h"

class trapezoid
{
	public:
		trapezoid(Function &f, double a, double b, int N);
                trapezoid(const trapezoid &obj);
                double Iin;
                double Ifin;
                int divisions;
                double integrate();
		static double integrate(const std::vector<double> &f, double h);
        private:
                Function &func;
};
#endif
