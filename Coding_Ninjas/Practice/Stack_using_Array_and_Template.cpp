#include<iostream>
using namespace std;

template <typename T>
class Stack
{
    T* data;
    int nextIndex;
    int capacity;

public:
     
     Stack()
     {
        capacity = 5;
        data = new T[capacity];
        nextIndex = 0;
     }

     // Size of stack
     int size()
     {
         return nextIndex;
     }

     // Check if stack is empty
     bool isEmpty()
     {
         return nextIndex == 0;
     }

     // Inserting an element in stack
     void push(T element)
     {
        if(nextIndex == capacity)
         {
             T* newData = new T[2*capacity];
             for(int i=0;i<capacity;i++)
             {
                 newData[i] = data[i];
             }

             capacity *= 2;
             delete[] data;
             data = newData;
         }

        data[nextIndex] = element;
        nextIndex++;
     }

     //Deleting an element from the stack
     T pop()
     {
         if(isEmpty())
         {
             cout<<"Stack is EMPTY"<<endl;
             return 0;
         }

         nextIndex--;
         return data[nextIndex];
     }

     // Element at the top of the stack
     T top()
     {
         if(isEmpty())
         {
             cout<<"Stack is EMPTY"<<endl;
             return 0;
         }

         return data[nextIndex-1];
     }

     // Displaying elements of the stack
     void display()
     {
         if(nextIndex == 0)
         {
             cout<<"Stack is EMPTY"<<endl;
             return;
         }

         for(int i=0;i<nextIndex;i++)
         {
             cout<<data[i]<<" ";
         }
         cout<<endl;
     }
};

int main()
{
    Stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.push('F');
    
    s.display();

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.isEmpty()<<endl;
    cout<<s.size()<<endl;

    s.display();
    return 0;
}