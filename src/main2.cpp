#include <iostream>
#include <cmath>

#include "bk/function.h"
#include "bk/trapezoid.h"

int main(){
        Function f;
        const double abar = 0.2;                       
        const double rs = 1.0 / std::sqrt(f.Qs0);    
        f.r = rs;

        const double rmax = 25.0 * rs;
        const double denom = 0.5 * std::exp(-0.25);    

        for (int m : {20, 40, 80, 160, 320}) {
                int divisions = 25 * m;
                trapezoid trap(f, 0.0, rmax, divisions);
                double I = trap.integrate();   
		double dNdy = abar / (2.0 * M_PI) * I;        
                std::cout << divisions << "        " << I << "     " << dNdy
                          << "     " << dNdy / denom << std::endl;
        }
        return 0;
}
