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
         firstIndex = -1;
         nextIndex = 0;
         size = 0;
     }

     // To get size of queue
     int getSize()
     {
         return size;
     }

     // To check if the queue is empty
     bool isEmpty()
     {
         return size==0;
     }

     // To insert an element in queue
     void enqueue(T element)
     {  
        if(size == capacity)
        {
            T* newData = new T[2 * capacity];
            int j =0;

            for(int i = firstIndex ; i < capacity ; i++)
            {
                newData[j] = data[i];
                j++;
            }

            for(int i = 0 ; i < firstIndex ; i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;

            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

         data[nextIndex] = element;
         nextIndex = (nextIndex + 1) % capacity;

         if(firstIndex == -1)
         {
             firstIndex = 0;
         }

         size++;
     }

     // To get front element of the queue
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
    Queue<char> q(5);

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('E');
    q.enqueue('F');

    cout<<q.front()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.front()<<endl;

    cout<<q.isEmpty()<<endl;
    cout<<q.getSize()<<endl;

    return 0;
}