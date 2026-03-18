#include <iostream>
using namespace std;

//FUNCTION OVERLOADING
void mul(int a) {
    cout << "mul " << (a * 10) << endl;
}
void mul(int a, int b) {
    cout << "mul " << (a * b) << endl;
}

int main() {
    mul(5);
    mul(5, 6);
    return 0;
}