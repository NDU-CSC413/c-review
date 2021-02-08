#include <iostream>

#define EX2
#ifdef EX1
//some change

int main() {
	//a location in memory is reserved and labeled x
	int x = 2;
	//y is just another name for the same location. no reservation is done.
	int& y = x;
	//a location is reserved for z and the value of x is copied
	int z = x;
	z = 17;
	y = 13;
	//print the value of the variables and their respective addresses
	std::cout << "x= " << x << " and &x=" << &x << std::endl;
	std::cout << "y= " << y << " and &y=" << &y << std::endl;
	std::cout << "z= " << z << " and &z=" << &z << std::endl;
}
#endif // EX1

#ifdef EX2

int main() {
	int x = 19, y = 23;

	//int &yr;//error a reference must be initialized
	int& yr = y;
	int& xr = x;
	/* if instead we declared const int& xr=x; then
	* the line below will generate an error
	*/
	/* this does NOT reassign xr to reference y
	* it merely assigns the value of y to xr and thus to x
	*/
	xr = yr;
	std::cout << "value of x=" << x << "\n";
	xr = 45;
	std::cout << "value of x=" << x << "\n";
	std::cout << "value of y=" << y << "\n";
}


#endif // EX2
