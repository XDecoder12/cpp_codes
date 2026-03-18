#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a Number";
    cin>>num;
    if (num>0){
        cout<<"The nUmber is positive";
     } else if (num<0){
        cout<<"The Number is negative";
     }
    else{
        cout<<"The Number is zero";
    }
       return 0;
};