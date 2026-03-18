#include <iostream>
using namespace std;

class Teacher{
    private:
    double salary;

    public:
       //no parameterized constructor 
       Teacher(){
            dept="CSE";
        }
        
        //parameterized constructor
        Teacher(string name,string subject,string dept,double salary){
            this->name=name;
            this->subject=subject;
            this->dept=dept;
            this->salary=salary;
        }

    string name;
    string subject;
    string dept;
    
    void changeDept(string newDept){
        dept=newDept;
    } 
   void getInfo(){
        cout<<"name:"<<name<<endl;
        cout<<"subject:"<<subject<<endl;
    }
};

int main() {
    Teacher t1("Krishay","CSE","C++",1500000);
   //t1.getInfo();

   Teacher t2(t1);
   t2.getInfo();
   return 0;
}