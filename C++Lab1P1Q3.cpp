#include<iostream>
using namespace std;
class Student {
public:
    string name;
    int age;

    void setData(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
int main() {
    Student students[3]; // Array of objects

    students[0].setData("Rahul", 20);
    students[1].setData("Aman", 21);
    students[2].setData("Priya", 19);

    for (int i = 0; i < 3; i++) {
        students[i].display();
    }

    return 0;
}
