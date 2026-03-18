#include <iostream>
using namespace std;
class rectangle{
    int length,width;
    public:
    rectangle(){
        length-0;
        width=0;
        cout<<"Constructor Called \n";
    }
    ~rectangle(){
        cout<<"Destructor Called \n";
    }
};
int main() {
    rectangle x;
    rectangle y;
    return 0;
}