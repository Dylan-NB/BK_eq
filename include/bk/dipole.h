#ifndef DIPOLE_H
#define DIPOLE_H

#include <vector>
#include <iostream>

class Dipole
{
        public:
                Dipole(double rmin, double rmax, int n);     // grilla uniforme en z = ln r

                void setGBW(double Qs0);                     // condición inicial (ec. 4.53), Qs0 = Q_s0^2
                double interpolate(double r) const;          // N(r) en cualquier r: interpola entre N_i y N_i+1
                void output(std::ostream &out) const;        // imprime y, r_j, N_j

                std::vector<double> r;                       // r_j
                std::vector<double> N;                       // N_j = N(y, r_j)
                double y = 0.0;                              // rapidez actual
                double zmin;                                 // ln(rmin)
                double dz;                                   // paso en ln r
};
#endif
