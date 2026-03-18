#include <iostream>
using namespace std;
class Time{
    int hour,minute,second;
    public:
    void getTime(){
        cout<<"\nEnter Hours:";cin>>hour;
        cout<<"Enter Minutes";cin>>minute;
        cout<<"Enter Seconds:";cin>>second;
    }
    void printTime(){
        cout<<"\nHour:"<<hour;
        cout<<"\tminute:"<<minute;
        cout<<"\tsecond:"<<second;
    }
    void addTime(Time x, Time y){
        hour = x.hour + y.hour;
        minute = x.minute + y.minute;
        second = x.second + y.second;
    }
};
int main()
{
    Time t1,t2,t3;

    t1.getTime();
    t1.printTime();

    t2.getTime();
    t2.printTime();

    t3.addTime(t1,t2);
    cout<<"\nafter adding two object";
    t3.printTime();
    return 0;
}