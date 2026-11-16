#include <iostream>
#include <cmath>
#include <vector>

#include "bk/function.h"
#include "bk/trapezoid.h"

int main(){
        Function f;                       
        const double rs = 1.0 / std::sqrt(f.Qs0);    
        f.r = rs;
	const double h = rs / 2000.0;

	//rmax fixed
	std::vector<double> col_rmax, col_rmin, col_I;   
	for (double rmax : {5.0 * rs, 10.0 * rs, 20.0 * rs }){
		for (int j = 0; j < 50; ++j){
			double rmin = j * 0.01 * rs;
			int divisions = (int)std::lround((rmax - rmin) / h);
			trapezoid trap(f, rmin, rmax, divisions);
			col_rmax.push_back(rmax);
			col_rmin.push_back(rmin);
			col_I.push_back(trap.integrate());
		}
        }

	//rmin fixed
	std::vector<double> col2_rmin, col2_rmax, col2_I;
	for (double rmin : {0.01 * rs, 0.1 * rs, 0.5 * rs}) {
                for (int j = 0; j < 49; ++j) {
                        double rmax = (2.0 + j) * rs;                      
                        int divisions = (int)std::lround((rmax - rmin) / h);
                        trapezoid trap(f, rmin, rmax, divisions);

                        col2_rmin.push_back(rmin);
                        col2_rmax.push_back(rmax);
                        col2_I.push_back(trap.integrate());
                }
        }
	//imprimir vectores (bloques 0, 1, 2)
        for (size_t k = 0; k < col_I.size(); ++k){
                std::cout << col_rmax[k] << " " << col_rmin[k] << " " << col_I[k] << std::endl;
                if (k % 50 == 49) std::cout << "\n\n";      
        }

        //imprimir vectores (bloques 3, 4, 5)
        for (size_t k = 0; k < col2_I.size(); ++k){
                std::cout << col2_rmin[k] << " " << col2_rmax[k] << " " << col2_I[k] << std::endl;
                if (k % 49 == 48) std::cout << "\n\n";
        }
}
