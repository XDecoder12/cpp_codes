#include <iostream>
using namespace std;

class ABC{
    public:
    void display(){
        cout<<"This is Parent Class";
    }
};
class XYZ:public ABC{
    public:
    void display(){
        cout<<"This is the child class\n";
    }
};
int main() {
    XYZ x;
    x.display();
    x.ABC::display(); //Function Overwriting
    return 0;
}