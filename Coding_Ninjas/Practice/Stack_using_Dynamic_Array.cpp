#include<iostream>
#include<climits>
using namespace std;

class Stack
{
private:
    int* data;
    int nextIndex;
    int capacity;

public:

    Stack()
    {
        capacity = 5;
        data = new int[capacity];
        nextIndex = 0;
    }

    // Size of Stack
    int size()
    {
        return nextIndex;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Inserting an element in the stack
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            int* newData = new int[2*capacity];
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

    // Element at the top of stack is
    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is EMPTY"<<endl;
            return INT_MIN;
        }

        return data[nextIndex-1];
    }

    // Displaying element in the stack
    void display()
    {
        if(isEmpty())
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
    Stack s;

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