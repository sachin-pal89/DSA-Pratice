#include<iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int currInd;
    int capacity;

    public:
        
        // Constructor
        DynamicArray()
        {
            data = new int[5];
            currInd = 0;
            capacity = 5;
        }
        
        // Add an element
        void add(int ele)
        {
            if(currInd == capacity)
            {
                int* newdata = new int[2 * capacity];
                for(int i=0; i < currInd ; i++)
                {
                    newdata[i] = data[i];
                }

                delete[] data;
                data = newdata;
                capacity *= 2;
            }

            data[currInd] = ele;
            currInd++;
        }

        // Update aur Add an element
        void update(int i, int ele)
        {
            if(i < currInd)
            {
                data[i] = ele;
            }
            else if(i == currInd)
            {
                add(ele);
            }
            else{
                return;
            }
        }

        // Copy Constructor
        DynamicArray(DynamicArray const &f1)
        {   
            this -> currInd = f1.currInd;
            this -> capacity = f1.capacity;

            this -> data = new int[capacity];
            for(int i=0; i < currInd; i++)
            {
                data[i] = f1.data[i];
            }
        }

        // Copy Assignment operator
        void operator=(DynamicArray const &f1)
        {
            this -> currInd = f1.currInd;
            this -> capacity = f1.capacity;

            this -> data = new int[f1.capacity];
            for(int i=0; i < currInd; i++)
            {
                data[i] = f1.data[i];
            }
        }
        
        // Get an element
        int get(int i)
        {
            if(i < currInd)
            {
                return data[i];
            }
            else
            {
                return -1;
            }
        }

        // Print
        void print()
        {
            for( int i=0; i < currInd; i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{   
    DynamicArray d1;

   for(int i=0; i<10;i++)
   {
       d1.add(i+1);
   }
   
   d1.print();

   d1.update(3,12);

   d1.print();

   DynamicArray d2(d1);
   
   d1.add(34);

   d1.print();
   d2.print();

    return 0;
}