#ifndef DIPOLE_H
#define DIPOLE_H

#include <vector>
#include <iostream>

class Dipole
{
        public:
                Dipole(double rmin, double rmax, int n);     // grilla uniforme en z = ln r

                void setGBW(double Qs0);                     // condición inicial (ec. 4.53)
                double interpolate(double r) const;          
                void output(std::ostream &out) const;        

                std::vector<double> r;                       
                std::vector<double> N;                       
                double y = 0.0;                              
                double zmin;                                 
                double dz;                                   
};
#endif
