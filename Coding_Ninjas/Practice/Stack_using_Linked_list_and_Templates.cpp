#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T data)
    {
        this-> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T>* head;
    int size ;

public:

    Stack()
    {
        head = NULL;
        size = 0;      
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void push(T element)
    {
        Node<T>* newNode = new Node<T>(element);
        
        newNode -> next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if(head==NULL)
           return 0;
        
        T ans = head->data;
        Node<T>* a = head;
        head = head->next;
        delete a;
        size--;

        return ans;
    }

    T top()
    {
        if(head==NULL)
          return 0;

        return head->data;
    }
};

int main()
{
    Stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.isEmpty()<<endl;

    cout<<s.top()<<endl;

    cout<<s.getSize()<<endl;

    return 0;
}