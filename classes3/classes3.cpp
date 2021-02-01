/* illustrate different constructors and assignment operators */
#include <iostream>
#include <exception>
struct Test {
    int _x;
    Test() {
        std::cout << "ctor\n";
    }
    Test(int x) :_x(x) {
        std::cout << " ctor " << x << "\n";
    }
    Test(const Test& rhs) {
        std::cout << " copy ctor\n";
        _x = rhs._x;
    }
    Test(Test&& rhs) {
        std::cout << "move ctor\n";
        _x = std::move(rhs._x);
    }

    Test& operator=(const Test& rhs) {
        std::cout << " assign \n";
        _x = rhs._x;
        return *this;
    }
    Test& operator=(Test&& rhs) {
        std::cout << "move assign\n";
        _x = rhs._x;
        return *this;
    }
};

int main()
{
    Test t1{ 1 };
    Test t2 = t1;
    t2._x = 2;
    t1 = t2;
    Test& t3 = t1;
    //Test& te = Test{ 4 }; error
    Test&& t4 = Test{ 4 };
    Test&& t5 = std::move(t1);
    Test t6 = std::move(t2);
    std::cout << "t3._x =" << t3._x << "\n";
    std::cout << "t4._x =" << t4._x << "\n";
    std::cout << "t5._x =" << t5._x << "\n";
    std::cout << "t6._x =" << t6._x << "\n";
    t6 = std::move(t1);
    std::cout << "t6._x =" << t6._x << "\n";
}

