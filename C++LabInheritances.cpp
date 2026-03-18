#include <iostream>
using namespace std;
class Animal{
    public:
     void sound(){
        cout<<"Animals Make sounds.";
     }
};
class dog:public Animal{
public:
void bark()

    cout<<"Dog Barks."<<endl;
}
};
int main() {
    dog d;
    d.sound();
    d.bark();
    return 0;
}
