
#include <iostream>
#include <string>
#include <vector>
//#define RVALR//rvalue reference
//#define PASS_ERROR //move semantics are not passed through
//#define PASS_OK
//#define TRANSF1 //transfer of ownership: std::string
//#define TRANSF2//transfer of ownership: std::vector
#define MOVE_TOR//move assignment and move constructor

#ifdef MOVE_TOR
struct Container {
    int* p = nullptr;
    int _size;
    Container(int size) :_size(size), p(new int[size] {}) {}
    Container(const Container& rhs) {//copy constructor
        if (&rhs != this) {
            _size = rhs._size;
            p = new int[_size];
            for (int i = 0; i < _size; ++i)
                p[i] = rhs.p[i];

        }

    }
    //usually there is also an assignment operator
    Container(Container&& rhs) {
        p = rhs.p;
        rhs.p = nullptr;
        rhs._size = 0;
    }
    Container& operator=(Container&& rhs) {
        if (p)delete[] p;
        p = rhs.p;
        _size = rhs._size;
        rhs._size = 0;
        rhs.p = nullptr;
        return *this;
    }
    void print() {
        for (int i = 0; i < _size; ++i)
            std::cout << p[i] << ",";
        std::cout << "\n";
    }
    ~Container() {
        if (p)delete[] p;
    }

};
#endif 

#ifdef RVALR
void f(const int& x) {
    std::cout << "using const int&\n";
}
void f(int&& x) {
    std::cout << "using int&&\n";
}
#endif
#ifdef PASS_ERROR
void f(std::string&& s) {
    if (s != "hello") {
        s = "hello";//to avoid infinite recursion
        f(s);
    }
}
#endif
#ifdef PASS_OK
void f(std::string&& s) {
    if (s != "hello") {
        s = "hello";
        f(std::move(s));
    }
}
#endif 
int main()
{
#ifdef RVALR
    int x = 8;
    f(x);
    f(12);
    f(std::move(x));
#endif 

#if defined(PASS_ERROR) || defined(PASS_OK)
    f("not hellow");
#endif

#ifdef TRANSF1
    std::string a = "hello";
    std::string b = std::move(a);
    std::cout << "a=" << a << "$\n";
    std::cout << "b=" << b << "$\n";
#endif 
#ifdef TRANSF2
    std::vector<int> v{ 1,2,3 };
    std::vector<int> u;
    u = std::move(v);
    std::cout << "content of v\n";
    for (auto& x : v)std::cout << x << ","; std::cout << "\n";
    std::cout << "content of u\n";
    for (auto& x : u)std::cout << x << ","; std::cout << "\n";
#endif 

#ifdef MOVE_TOR
    Container c(10);
    c.print();
    Container d(std::move(c));
    c.print();
    Container e(3);
    d = std::move(e);
    d.print();
#endif 

}
