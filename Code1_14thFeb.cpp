#include <iostream>
using namespace std;
class rectangle
{
    int height;
    int width;
public:
    void setValue(int x,int y );
    float area(){
        return height*width;  
    }
};
void rectangle:: setValue(int x,int y){
    width = x; height = y;
}

int main(){
    int h,w;
    rectangle r1,r2;
    r1.setValue(2,3);
    cout << r1.area();
    return 0;
}