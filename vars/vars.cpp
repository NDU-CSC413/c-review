#include <iostream>
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