#include <iostream>
#include <cmath>
#include <vector>

#include "bk/BKec.h"
#include "bk/trapezoid.h"

std::vector<double> rhs(const Dipole &dip, double abar)
{
        int n = dip.N.size();
        std::vector<double> F(n, 0.0);

        for (int j = 0; j < n; ++j) {                   
                double rj = dip.r[j];  // dipolo padre en r
                std::vector<double> f(n, 0.0);
                for (int k = 0; k < n; ++k) {
                        if (k == j) continue;            // singularidad r' = r: queda en 0
                        double rk = dip.r[k];
                        double r2 = std::fabs(rj - rk);
                        double N2 = dip.interpolate(r2);
                        double bracket = dip.N[k] + N2 - dip.N[j] - dip.N[k] * N2;
                        double K = (rj * rj) / ((rk * rk) * (r2 * r2));
                        f[k] = rk * (2.0 * M_PI * rk * K * bracket);   // jacobiano dr' = r' dz'
                }

                F[j] = abar / (2.0 * M_PI) * trapezoid::integrate(f, dip.dz);  
        }
        return F;
}
