#include <iostream>
#include <cmath>
#include <vector>

#include "bk/function.h"
#include "bk/trapezoid.h"

int main(){
        Function f;
        f.useLog = true;                               //integrar en z = ln r'
        const double rs = 1.0 / std::sqrt(f.Qs0);      
        f.r = rs;

        const double dz = std::log(10.0) / 400.0;      
        const double zs = std::log(rs);                

        //rmax fixed
        std::vector<double> col_rmax, col_rmin, col_I;
        for (double rmax : {5.0 * rs, 10.0 * rs, 20.0 * rs}){
                double lmin = std::log(1e-4 * rs), lmax = std::log(0.5 * rs);
                for (int j = 0; j < 50; ++j){
                        double rmin = std::exp(lmin + j * (lmax - lmin) / 49.0);

                        double zmin = std::log(rmin);
                        double zmax = std::log(rmax);

                        int pasosIzq = (int)std::lround((zs - zmin) / dz);   // de rmin a r_s
                        int pasosDer = (int)std::lround((zmax - zs) / dz);   // de r_s a rmax

                        zmin = zs - pasosIzq * dz;
                        zmax = zs + pasosDer * dz;

                        trapezoid trap(f, zmin, zmax, pasosIzq + pasosDer);

                        col_rmax.push_back(std::exp(zmax));
                        col_rmin.push_back(std::exp(zmin));
                        col_I.push_back(trap.integrate());
                }
        }

        //rmin fixed
        std::vector<double> col2_rmin, col2_rmax, col2_I;
        for (double rmin : {1e-4 * rs, 0.01 * rs, 0.1 * rs}) {
                double lmin = std::log(2.0 * rs), lmax = std::log(50.0 * rs);
                for (int j = 0; j < 49; ++j) {
                        double rmax = std::exp(lmin + j * (lmax - lmin) / 48.0);

                        double zmin = std::log(rmin);
                        double zmax = std::log(rmax);

                        int pasosIzq = (int)std::lround((zs - zmin) / dz);   // de rmin a r_s
                        int pasosDer = (int)std::lround((zmax - zs) / dz);   // de r_s a rmax

                        zmin = zs - pasosIzq * dz;
                        zmax = zs + pasosDer * dz;

                        trapezoid trap(f, zmin, zmax, pasosIzq + pasosDer);

                        col2_rmin.push_back(std::exp(zmin));
                        col2_rmax.push_back(std::exp(zmax));
                        col2_I.push_back(trap.integrate());
                }
        }

        for (size_t k = 0; k < col_I.size(); ++k){
                std::cout << col_rmax[k] << " " << col_rmin[k] << " " << col_I[k] << std::endl;
                if (k % 50 == 49) std::cout << "\n\n";
        }

        for (size_t k = 0; k < col2_I.size(); ++k){
                std::cout << col2_rmin[k] << " " << col2_rmax[k] << " " << col2_I[k] << std::endl;
                if (k % 49 == 48) std::cout << "\n\n";
        }

        return 0;
}
