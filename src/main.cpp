#include <iostream>

#include "bk/function.h"
#include "bk/RungeKutta4.h"

int main(){
  	Function f;                          
  	RungeKutta4 rk4(f, 0.0, 1/3.0, 20.0, 0.01);

  	double result = rk4.method();

 // 	std::cout << "Final result: y(" << 1.0 << ") = " << result << std::endl;

 // 	std::cout << "\nFull trajectory:" << std::endl;
  	for(size_t i = 0; i < rk4.xValues.size(); ++i){
 //   		std::cout << "x = " << rk4.xValues[i] << ", y = " << rk4.yValues[i] << std::endl;
		std::cout << rk4.xValues[i] << " " << rk4.yValues[i] << std::endl;
  	}
return 0;
}
