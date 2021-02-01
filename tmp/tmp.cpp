#include <iostream>
#include <type_traits>
#include <utility>

/* https://en.cppreference.com/w/cpp/utility/forward */
struct Test {};


void what(int& t) {
    std::cout << "int&\n";
}
void what(int&& t) {
    std::cout << "int&&\n";
}
void what(const int& t) {
    std::cout << "const int&\n";
}
template <typename T>
void check(T&& t) {
    what(std::forward<T>(t));

}
int main()
{
    int a[10];
    AbyVal(a);
    int x = 8;

    AbyRef(a);
    const int z = 67;
    check(z);
    check(x);
    check(19);
    int&& y = 23;
    check(std::move(y));
 /*   what(8);
    what(std::move(x));
    what([]() {return 18; }());*/
}
