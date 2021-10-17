#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    
    // Constructor
    Stack(int totalsize)
    {
        data = new int[totalsize];
        capacity = totalsize;
        nextIndex = 0;
    }

    // Size of a stack
    int size()
    {
        return nextIndex;
    }

    // Check if Stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Inserting an element in the stack
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            cout<<"Stack is FULL"<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // Deleting an element in the stack
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is EMPTY"<<endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // To get element at the top of stack
    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is EMPTY"<<endl;
            return INT_MIN;
        }

        return data[nextIndex-1];
    }

    // To Display element of the Stack;
    void display()
    {
        if(nextIndex==0)
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
    Stack s(5);

    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    
    s.display();

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.isEmpty()<<endl;
    cout<<s.size()<<endl;

    s.display();
    return 0;
}