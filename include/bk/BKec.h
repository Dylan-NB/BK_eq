#ifndef BK_H
#define BK_H

#include <vector>
#include "dipole.h"

// Lado derecho de BK (1D): devuelve F_j = dN/dy en cada punto r_j de la grilla
std::vector<double> rhs(const Dipole &dip, double abar);

#endif
