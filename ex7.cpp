#include<iostream>
#include<string> // Replaced old stdio.h with string for easier text handling
using namespace std;

class Student
{
    int roll;
    string name; // Changed from char array to string to allow spaces securely
public:
    void getdata()
    {
        cout<<"\n -----------------------------------------";
        cout<<"\n Enter Roll No. : ";
        cin>>roll;
        
        cout<<" Enter Student Name : ";
        cin.ignore(); // Clears the input buffer newline character
        getline(cin, name); // Allows reading full names with spaces
    }
    void putdata()
    {
        cout<<"\n -----------------------------------------";
        cout<<"\n ********** Student Marklist **********";
        cout<<"\n -----------------------------------------";
        cout<<"\n Roll No. : "<<roll;
        cout<<"\n Student Name : "<<name<<endl;
    }
};

class StudentExam : public Student 
{
public:
    int sub1, sub2, sub3, sub4, sub5, sub6;
    float per;
public:
    void accept_data()
    {
        getdata();
        cout<<" Enter Marks for Subject 1 : "; cin>>sub1;
        cout<<" Enter Marks for Subject 2 : "; cin>>sub2;
        cout<<" Enter Marks for Subject 3 : "; cin>>sub3;
        cout<<" Enter Marks for Subject 4 : "; cin>>sub4;
        cout<<" Enter Marks for Subject 5 : "; cin>>sub5;
        cout<<" Enter Marks for Subject 6 : "; cin>>sub6;
    }
    void display_data()
    {
        putdata();
        cout<<" Marks of Subject 1 : "<<sub1<<endl;
        cout<<" Marks of Subject 2 : "<<sub2<<endl;
        cout<<" Marks of Subject 3 : "<<sub3<<endl;
        cout<<" Marks of Subject 4 : "<<sub4<<endl;
        cout<<" Marks of Subject 5 : "<<sub5<<endl;
        cout<<" Marks of Subject 6 : "<<sub6<<endl;
    }
};

class StudentResult : public StudentExam 
{
public:
    void calculate ()
    {
        per = (sub1+sub2+sub3+sub4+sub5+sub6)/6.0;
        cout<<" Total Percentage : "<<per<<"%";
        cout<<"\n ----------------------------------------- \n";
    }
};

int main()
{
    int cnt, i;
    cout<<"\n Enter No. of Students You Want? : ";
    cin>>cnt;
    
    // Creating an array of objects dynamically so multiple student profiles can work
    StudentResult* str = new StudentResult[cnt]; 
    
    for(i=0; i<cnt; i++)
    {
        cout << "\n--- Entering Details for Student " << (i+1) << " ---";
        str[i].accept_data();
    }
    
    cout << "\n\n================ GENERATING RESULTS ================";
    for(i=0; i<cnt; i++)
    {
        str[i].display_data();
        str[i].calculate();
    }
    
    delete[] str; // Freeing up memory
    return 0;
}
