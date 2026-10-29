#include <iostream>

#include <function.h>
#include <RungeKutta2.h>

int main(){
  	Function f;                          
  	RungeKutta2 rk2(f, 0.0, 1.0, 1.0, 0.1);

  	double result = rk2.method();

  	std::cout << "Final result: y(" << 1.0 << ") = " << result << std::endl;

  	std::cout << "\nFull trajectory:" << std::endl;
  	for(size_t i = 0; i < rk2.xValues.size(); ++i){
    		std::cout << "x = " << rk2.xValues[i] << ", y = " << rk2.yValues[i] << std::endl;
  	}
return 0;
}
