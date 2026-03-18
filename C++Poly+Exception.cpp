#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    } };
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    } };
int main() {
    try {  //Basically include everything that can cause an error in this block
        Shape *s;
        Circle c;
        s = &c;
        s->draw(); // Calls Circle's draw()
        
        throw "An error occurred"; //throw this statement if exception is not caught
    } catch (const char* msg) {
        cout << "Exception Caught: " << msg << endl; //statement for adding exception
    }
    return 0;
}
