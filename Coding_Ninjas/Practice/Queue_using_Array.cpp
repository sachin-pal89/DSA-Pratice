#include<iostream>
using namespace std;

template <typename T>
class Queue
{
    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:

     Queue(int capacity)
     {
         this->capacity = capacity;
         data = new T[capacity];
         nextIndex = 0;
         firstIndex = -1;
         size = 0;
     }
    
    // To get size of the queue
     int getSize()
     {
         return size;
     }
    
    // To check whether queue is empty or not
     bool isEmpty()
     {
         return size==0;
     }
    
    // To insert an element in queue
    void enqueue(T element)
    {   
        if(size == capacity)
        {
            cout<<"Queue is FULL"<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;

        if(firstIndex == -1)
        {
            firstIndex = 0;
        }
        
        size++;
    }

    // To get the front element of the queue
    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is EMPTY"<<endl;
            return 0;
        }

        return data[firstIndex];
    }

    // To delete an element from the queue
    T dequeue()
    {  
        if(isEmpty())
        {
           cout<<"Queue is EMPTY"<<endl;
           return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;

        if(size==0)
        {
           firstIndex = -1;
           nextIndex = 0;
        }

        return ans;
    }
};

int main()
{
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;

    cout<<q.isEmpty()<<endl;
    cout<<q.getSize()<<endl;

    return 0;
}