
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <type_traits>
//#define RVALR//rvalue reference
//#define PASS_ERROR //move semantics are not passed through
//#define PASS_OK
//#define TRANSF1 //transfer of ownership: std::string
#define TRANSF2//transfer of ownership: std::vector
//#define MOVE_TOR //move assignment and move constructor


#ifdef RVALR
int y = 14;
int byValue() { return y; }
void f(const int& x) {
    std::cout << "using const int&\n";
}
void f(int&& x) {
    std::cout << "using int&&\n";
}
int main()
{
    int x = 8;
    f(x);
    f(12);
    f(std::move(x));
    f(byValue());
}
#endif 

#ifdef PASS_ERROR
void f(std::string& s) {
    std::cout << "choosing std::string&\n";
}
void f(std::string&& s) {// rvalues are not passed
    std::cout << "calling string&&\n";
    if (s != "hello") {
        s = "hello";//to avoid infinite recursion
        f(std::move(s));
    }
}


int main() {
    std::string s = "not hello";
   // f(s);
    f("not hello");
}
#endif
#ifdef PASS_OK
void f(std::string&& s) {
    if (s != "hello") {
        s = "hello";
        f(std::move(s));
    }
}
int main() {
    f("not hello");
}
#endif 

#ifdef TRANSF1
int main() {
    std::string a = "hello";
    std::string b = std::move(a);
    std::cout << "a=" << a << "$\n";
    std::cout << "b=" << b << "$\n";
}
#endif 
#ifdef TRANSF2
int byVal() {
    return 9;
}
int main() {
    std::vector<int> v{ 1,2,3 };
    std::vector<int> u;
    u = std::move(v);
    std::vector<int>::iterator itr;
   
  /*  std::cout << "content of v\n";
    
    for (auto& x : v)std::cout << x << ","; std::cout << "\n";
    std::cout << "content of u\n";
    for (auto& x : u) { std::cout << x << ","; } std::cout << "\n";*/
    /*for (auto&& x : u) {
        if (std::is_same_v<decltype(x), int&>)std::cout << "int&\n";
        else if (std::is_same_v<decltype(x), int&&>)std::cout << "int&&\n";
        else std::cout << "none\n";
    }*/
    auto&& value = byVal();
    int x = 12;
    decltype(x) y;
    if (std::is_same_v<decltype(value), int&>)std::cout << "int&\n";
    else if (std::is_same_v<decltype(value), int&&>)std::cout << "int&&\n";
    else std::cout << "none\n";
}
#endif 

#ifdef MOVE_TOR
struct Container {
    int* p = nullptr;
    int _size;

    Container(std::initializer_list<int> list)
        :_size(list.size()), p(new int[list.size()]) {
        int* tmp = p;
        for (auto itr = list.begin(); itr != list.end(); ++itr)
            *tmp++ = *itr;

    }
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
int main() {
    Container c{ 1,2,3,4 };

    std::cout << "initial values of container c: ";
    c.print();
    Container d = std::move(c);
    std::cout << "values of c after d=std::move(c):";
    c.print();
    std::cout << "values of d after d=std::move(c):";
    d.print();
    Container e{ 9,8,7,6 };
    d = std::move(e);
    std::cout << "values of d after d=std::move(e):";
    d.print();
}
#endif 

