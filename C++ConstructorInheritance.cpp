#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal constructor called" << endl;
    }
};
class Dog : public Animal {
public:
    Dog() {
        cout << "Dog constructor called" << endl;
    }
};
int main() {
    Dog d; // Output will show both constructors being called
    return 0;
}