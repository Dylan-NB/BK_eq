#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
	public:
		double evaluate(double x, double y); //to test RungeKutta4
		double evaluate(double x);           //to test trapezoid		   				
		Function();
		~Function();
};
#endif
