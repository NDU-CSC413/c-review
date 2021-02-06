#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

/* EX1-> function templates
*  EX2-> template specialization
*  EX3-> using auto
*  EX4-> class templates
*/
#define EX4

#ifdef EX1
template <typename T>
T add(T a, T b) {
	return a + b;
}
#endif // EX1
#ifdef EX2
template <typename T>
T add(T a, T b) {
	return a + b;
}
template<>
char add<char>(char a, char b) {
	return a < b ? b + (b - a) : a + (a - b);
}
#endif // EX2


#ifdef EX3
template <typename T>
auto add(T a, T b) {
	return a + b;
}
template<>
auto  add<char>(char a, char b) {
	/* either one would work */
	//return std::string(1, a) + std::string(1, b);
	return std::string({ a,b });
}

#endif //EX3
#if defined (EX1) || defined (EX2) || defined(EX3)
int main() {
	float x = 1.2, y = 3.4;
	int i = 2, j = 9;
	char a = 'a', b = 'b';
	std::string u = "hello ", v = "there";
	std::cout << "x+y=" << add(x, y) << "\n";
	std::cout << "i+j=" << add(i, j) << "\n";
	std::cout << "v+y=" << add(u, v) << "\n";
	std::cout << "a+b=" << add(a, b) << "\n";
}
#endif 


#ifdef EX4
struct Test {};
template <typename T>
class Stack {
	std::vector<T> _data;
	void push(const T& d) {
		_data.push_back(d);
	}
	const T& top() {
		return _data.back();
	}
	void pop() {
		if (!_data.empty())_data.pop_back();
	}
};
int main() {
	Stack<int> stack_of_int;
	Stack<std::string> stack_of_string;
	Stack<Test> stack_of_test;
}
#endif // EX4




