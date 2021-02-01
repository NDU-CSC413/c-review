#include <iostream>
/* member variables and functions,initialization, accessibility qualifiers */
class Test {
	int _x;
public: int& x() {return _x;}
	int _z;//z is public. Carries over.
private: //newline has no effect. Same as public: int_y;
	int _y;
public: int& y() { return _y;}
	
};
int main() {

	Test t1, t2;
	std::cout << "value of _x in t1 is " << t1.x() << "\n";
	std::cout << "value of _x in t2 is " << t2.x() << "\n";


	//t1._x = 17; error
	//t2._y = 33; error
	t1._z = 45;//ok
	t1.x() = 17;//returnin by reference allows us to change the value
	std::cout << "value of _x in t1 is " << t1.x() << "\n";



}