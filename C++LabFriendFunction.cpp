#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    Box() {
        length = 10;
    }
    // Friend function
    friend void showLength(Box obj);
};
// Friend function definition
void showLength(Box obj) {
    cout << "Length: " << obj.length << endl;
}
int main() {
    Box b;
    showLength(b); // Calling friend function
    return 0;
}