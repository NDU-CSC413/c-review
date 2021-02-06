#include <iostream>
/* classes containing references or constants 
* have their assignment operator automatically
* deleted
*/
struct TestRef {
    int& _x;
    TestRef(int& x) :_x(x) {}
};
struct TestConst {
    const int _x;
    TestConst(int x) :_x(x) {}
};
int main()
{
    int x = 12;
    TestRef t(x);
    TestRef p(x);
    TestConst c(x);
    TestConst d(x);
    p = t;
    c = d;
}


