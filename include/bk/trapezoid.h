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
        private:
                Function &func;
                trapezoid();
};
#endif
