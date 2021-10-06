#include<iostream>
#include<string.h>
using namespace std;

// We are creating a copy constructor by ourself and would also learn about shallow copy and deep copy

class Student
{
   int age;

   public :
       char* name;

    // Here we will see type of copy
    Student(int age, char* name)
    {
        this -> age = age;

        /*Shallow copy :- it will save the same address of name for all the object that would be created. 
                         thus it can led to change of value in name of all objects even if changes occur in anyone of them
        */
        //  this -> name = name;  

        // Deep copy :- it basically creates an new array for name which is class memeber thus changes in other objects name value would not effect it.
        this -> name = new char[strlen(name) + 1];  // +1 for adding null character at end
        strcpy(this -> name, name);
    }


    // Copy Constructor
    Student(Student const &s2)
    {
        this -> age = s2.age;
        
        // Deep Copy
        this -> name = new char[strlen(s2.name) + 1];
        strcpy(this -> name, s2.name);
    }

    void print()
    {
        cout<<"Age: "<<age<<" "<<"Name: "<<name<<endl;
    }

};

int main()
{  
   char name[] = "Sachin";

   Student s1(18,name);
   s1.print();

   Student s2(s1);

   s2.name[0]='P';

   s1.print();
   s2.print();

   return 0;
}