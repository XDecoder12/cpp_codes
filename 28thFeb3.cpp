#include<iostream>
using namespace std;

//INLINE FUNCTION
inline void square(int x)
{
    cout<<"Square "<<x*x<<endl;
}
int main(){
    square(5);
    square(7);
    return 0;
}