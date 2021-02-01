#include <iostream>
/* order of constructor and destructor of member variables */
struct Item {
	Item() {
		std::cout << "Item ctor\n";
	}
	~Item() {
		std::cout << "Item dtor\n";
	}
};
struct Test {
	Item _i;
	Test() {
		std::cout << "Test ctor\n";
	}
	~Test() {
		std::cout << "Test dtor\n";
	}
};
int main() {
	Test t;
}