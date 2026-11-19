#include <iostream>
#include <cmath>
#include <vector>

#include "bk/dipole.h"

// Lado derecho de BK en 1D 
std::vector<double> rhs(const Dipole &dip, double abar)
{
        int n = dip.N.size();
        std::vector<double> F(n, 0.0);

        for (int j = 0; j < n; ++j) {                    
                double rj = dip.r[j];
                double suma = 0.0;
                for (int k = 0; k < n; ++k) {            
                        if (k == j) continue;            
                        double rk = dip.r[k];
                        double r2 = std::fabs(rj - rk);
                        double N2 = dip.interpolate(r2);
                        double bracket = dip.N[k] + N2 - dip.N[j] - dip.N[k] * N2;
                        double K = (rj * rj) / ((rk * rk) * (r2 * r2));
                        double w = (k == 0 || k == n - 1) ? 0.5 : 1.0;   // pesos del trapecio
                        suma += w * rk * (2.0 * M_PI * rk * K * bracket); // jacobiano dr' = r' dz'
                }
                F[j] = abar / (2.0 * M_PI) * suma * dip.dz;
        }
        return F;
}

void Step(Dipole &dip, double dy, double abar)
{
        std::vector<double> F = rhs(dip, abar);
        for (size_t j = 0; j < dip.N.size(); ++j)
                dip.N[j] += dy * F[j];
        dip.y += dy;
}

int main(){
        const double abar = 0.2;
        const double dy = 0.05;

        Dipole dip(1e-6, 1e2, 800);                     
        dip.setGBW(0.24);
        dip.output(std::cout);                          // y = 0

        for (int paso = 1; paso <= 20; ++paso) {
                Step(dip, dy, abar);
                if (paso % 5 == 0)
                        dip.output(std::cout);          // cada 5 pasos
        }
        return 0;
}
