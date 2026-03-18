#include <iostream>
using namespace std;
class Student {
public:
    string Name;
    int Roll_No;
    int marks;
public:
    void input_data() {
        cout << "Enter Student Name: ";
        cin >> Name;
        cout << "Enter Roll_No: ";
        cin >> Roll_No;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void displaydata() {
        cout << "Student Name: " << Name << "\n";
        cout << "Roll_No: " << Roll_No << "\n";
        cout << "Marks: " << marks << "\n";
    }
};
int main() {
    Student S;
    S.input_data();
    S.displaydata();
    return 0;
}