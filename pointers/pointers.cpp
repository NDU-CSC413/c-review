#include <iostream>

#define EX2 //basics

#ifdef EX1
int main()
{
    const int n = 8;
    int a[n];
    for (int i = 0; i < n; ++i)a[i] = i;
    int x = 12;
    int* p = &x;
    *p = 15;
    std::cout << x << "\n";
    p = a;
    p += 4;
    *p = 99;
    *++p = 100;
    p = a;
    *p++ = 101;
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << ",";
    std::cout << "\n";
}
#endif // EX1
#ifdef EX2

int main() {
    int n = 8;
    int* p;
    p = new int[8];

    /* p IS a variable
    * so we make a copy
    * before changing it
    */
    for (int i = 0,*q=p; i < n; ++i,++q)
        *q = i;

    for (int i = 0; i < n; ++i)
        std::cout << p[i] << ",";
    std::cout << "\n";
}

#endif // EX2

