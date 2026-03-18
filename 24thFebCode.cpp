#include <iostream>
#include <string>
using namespace std;

class Train {
public:
    int train_number;
    string train_name;
    string source;
    string destination;
    string journey_date;
    int capacity;

public:
    void input_train_data() {
        cout << "Enter Train Number: ";
        cin >> train_number;
        cout << "Enter Train Name: ";
        cin >> train_name;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Journey Date: ";
        cin >> journey_date;
        cout << "Enter Capacity: ";
        cin >> capacity;
    }

    void displaydata() {
        cout << "Train Number: " << train_number << "\n"
             << "Train Name: " << train_name << "\n"
             << "Source: " << source << "\n"
             << "Destination: " << destination << "\n"
             << "Journey Date: " << journey_date << "\n"
             << "Capacity: " << capacity << "\n";
    }
};

int main() {
    Train t;
    t.input_train_data();
    t.displaydata();
    return 0;
};