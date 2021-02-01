#include <iostream>

int byT(int n) {
    return 7 * n;
}
int byCRef(const int& n) {
    //n=n+1;//error n is const
    return 2 * n;
}
int byRef(int& n) {
    n = n + 1;//changes the value of parameter
    return 2 * n;
}

int main() {
    //byRef(2);//error cannot bind a non-const lvalue to rvalue
    byCRef(2);//OK
    //byRef(byT(2));//error since the return value of byT is a temp
    byCRef(byT(2));//OK
    //int& r=byT(2);//error cannot bind 
    int&& r = byT(2);
    std::cout << "finished\n";
}