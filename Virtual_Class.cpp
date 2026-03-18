#include <iostream>
using namespace std;

class A{
    public:
    int i;
};
class B: public A{
    public:
    int j;
};
class C:public A{
    public:
    int k;
};
class D:public B, public C{
    public:
    int sum;
};

int main() {
    D ob1;
    ob1.i;
    ob1.j;
    ob1.k;
    ob1.sum=ob1.i+ob1.j+ob1.k;
    cout<<ob1.sum;
    return 0;
}