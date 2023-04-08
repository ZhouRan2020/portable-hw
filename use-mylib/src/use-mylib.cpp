#include <iostream>
#include "../static-portable/include/mymath.h"
#include "../shared-portable/include/mymathdll.h"
int main(int argc, char** argv){
	int a=114514;
	plusone(a);
	std::cout<<"now a is: "<<a<<std::endl;
	int b=plusonedll(a);
	std::cout<<"return value is: "<<b<<std::endl;
	return 0;
}