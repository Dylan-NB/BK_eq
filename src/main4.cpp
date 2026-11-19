#include <iostream>

#include "bk/dipole.h"
#include "bk/RungeKutta4.h"

int main(){
        const double abar = 0.2;
        const double dy = 0.05;

        Dipole dip(1e-6, 1e2, 800);                     
        dip.setGBW(0.24);
        dip.output(std::cout);                          // y = 0

        for (int paso = 1; paso <= 200; ++paso) {
                RungeKutta4::stepDipole(dip, dy, abar); 
                if (paso == 20 || paso == 100 || paso == 200) // y = 1, 5 y 10
                        dip.output(std::cout);          // cada 5 pasos
        }
        return 0;
}
