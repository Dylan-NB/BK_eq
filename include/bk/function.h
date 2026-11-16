#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
	public:
		double evaluate(double x, double y); //to test RungeKutta4
		double evaluate(double rp);           //to test trapezoid
		double N0(double r);
		double r = 1.0;
		double Qs0 = 0.24; // (GeV)^2
		bool useLog = false;		   				
		Function();
		~Function();
};
#endif
