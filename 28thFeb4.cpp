#include <iostream>
using namespace std;

//DEFAULT ARGUMENTS

int sum(int x=10,int y=20, int z=30)
{
    return(x+y+z);
}

int main() {
    cout<<"The Sum is:"<<sum(10)<<endl;
    cout<<"The Sum is:"<<sum(10,25)<<endl;
    cout<<"The Sum is:"<<sum(10,20,45)<<endl;
    return 0;
}