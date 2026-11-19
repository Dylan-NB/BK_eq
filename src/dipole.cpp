#include <iostream>
#include <cmath>

#include "bk/dipole.h"

Dipole::Dipole(double rmin, double rmax, int n)
{
        zmin = std::log(rmin);
        dz = (std::log(rmax) - zmin) / (n - 1);
        for (int j = 0; j < n; ++j) {
                r.push_back(std::exp(zmin + j * dz));   // r_j = exp(ln(rmin) + j dz)
                N.push_back(0.0);
        }
}

void Dipole::setGBW(double Qs0)
{
        for (size_t j = 0; j < r.size(); ++j)
                N[j] = 1 - std::exp(-r[j] * r[j] * Qs0 / 4.0);
        y = 0.0;
}

// Interpolación lineal 
double Dipole::interpolate(double rr) const
{
        int n = N.size();
        if (rr <= r[0])     return N[0] * (rr * rr) / (r[0] * r[0]);   // debajo de la grilla: N ~ r^2 (sale expandiendo en Taylor la ec 4.53)
        if (rr >= r[n - 1]) return N[n - 1];                             // arriba de la grilla: saturado

        double t = (std::log(rr) - zmin) / dz;   // posición en la grilla 
        int i = (int)t;                          // nodo de la izquierda
        if (i > n - 2) i = n - 2;
        double w = t - i;                        // qué tan cerca está de i+1 (entre 0 y 1)
        return (1.0 - w) * N[i] + w * N[i + 1];
}

void Dipole::output(std::ostream &out) const
{
        for (size_t j = 0; j < r.size(); ++j)
                out << y << " " << r[j] << " " << N[j] << "\n";
        out << "\n\n";                           
}
