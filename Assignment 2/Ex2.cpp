#include<iostream>
using namespace std;

class Student
{
    public:
        int rno;
        char name[20];
        float marks;

        void input(){
            cout<<"Enter Roll no"<<endl;
            cin>>rno;
            cout<<"Enter Name :"<<endl;
            cin>>name;
            cout<<"Enter Marks"<<endl;
            cin>>marks;
        }
        void output(){
            cout<<"\nRoll Number:"<<rno<<endl;
            cout<<"Student Name:"<<name<<endl;
            cout<<"Student Marks:"<<marks<<endl;


        }

};

 int main(){
    Student S;
    S.input();
    S.output();
    return 0;
 }