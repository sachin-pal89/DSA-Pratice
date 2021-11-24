#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

// THIS IS A PRIORITY QUEUE OF MIN-HEAP TYPE Using Class
/* 
class PriorityQueue
{
   vector<int> pq;

   public:

      // TO CHECK WHETHER THE VECTOR IS EMPTY OR NOT
      bool isEmpty()
      {
          return pq.size() == 0;
      }

      //TO GET THE NO OF ELEMENT IN PRIORITY QUEUE
      int getSize()
      {
          return pq.size();
      }

      // TO GET THE MINIMUM IN PRIORITY QUEUE
      int getMin()
      {
          if(isEmpty())
          {
              return 0;
          }
          return pq.at(0);
      }

      void insert(int data)
      {
          pq.push_back(data);

          int childIndex = pq.size()-1;

          while(childIndex > 0)
          {
              int parentIndex = ( childIndex - 1 ) / 2;

              if(pq[childIndex] < pq[parentIndex])
              {
                  int temp = pq[childIndex];
                  pq[childIndex] = pq[parentIndex];
                  pq[parentIndex] = temp;
              }
              else{
                  break;
              }

              childIndex = parentIndex;
          }
      }

      int removeMin()
      {
          if(isEmpty())
          {
              return INT_MIN;
          }

          int ans = pq[0];
          pq[0] = pq[pq.size()-1];
          pq.pop_back();

          int size = pq.size();
          int parentIndex = 0;
          int LchildIndex = (2*parentIndex) + 1;
          int RchildIndex = (2*parentIndex) + 2;

          while(parentIndex < size)
          {
             
             int temp = pq[parentIndex];
             if(LchildIndex >= size && RchildIndex >= size)
             {
                 break;
             }
             else if(LchildIndex >= size)
             {
                 pq[parentIndex] = pq[RchildIndex];
                 pq[RchildIndex] = temp;

                 parentIndex = RchildIndex;
             }
             else if(RchildIndex >= size)
             {
                pq[parentIndex] = pq[LchildIndex];
                pq[LchildIndex] = temp;

                parentIndex = LchildIndex;
             }
             else{

                 int mini = min(temp,min(pq[LchildIndex],pq[RchildIndex]));

                 if(mini == temp)
                 {
                     break;
                 }
                 else if(mini == pq[LchildIndex])
                 {
                    pq[parentIndex] = pq[LchildIndex];
                    pq[LchildIndex] = temp;

                    parentIndex = LchildIndex;
                 }
                 else if(mini == pq[RchildIndex])
                 {
                    pq[parentIndex] = pq[RchildIndex];
                    pq[RchildIndex] = temp;

                    parentIndex = RchildIndex; 
                 }
             }

              LchildIndex = (2*parentIndex) + 1;
              RchildIndex = (2*parentIndex) + 2;
          }

          return ans;
      }
};
*/

// Inplace Heap Sort 
/*
int createHeap(int arr[],int n,int heapIndex)
{
    if(heapIndex >= n)
    {
        return n-1;
    }
    
    int childIndex = heapIndex;
    
    while(childIndex > 0)
    {
        int parentIndex = (childIndex - 1) / 2;
        
        if(arr[parentIndex] < arr[childIndex])
        {
            break;
        }
        
        int temp = arr[parentIndex];
        arr[parentIndex] = arr[childIndex];
        arr[childIndex] = temp;
        
        childIndex = parentIndex;
    }
    
    return createHeap(arr,n,heapIndex+1);
}

void sortByRemove(int arr[],int n,int heapIndex)
{
    if(heapIndex < 1)
    {
        return;
    }
    
    int temp = arr[heapIndex];
    arr[heapIndex] = arr[0];
    arr[0] = temp;
    
    
    int parentIndex = 0;
    int leftchildIndex = (2 * parentIndex) + 1;
    int rightchildIndex = (2 * parentIndex) + 2;
    
    while(leftchildIndex < heapIndex)
    {
        int minIndex = parentIndex;
        
        if(arr[leftchildIndex] < arr[minIndex])
        {
            minIndex = leftchildIndex;
        }
        
        if(rightchildIndex < heapIndex && arr[rightchildIndex] < arr[minIndex])
        {
            minIndex = rightchildIndex;
        }
        
        if(minIndex == parentIndex)
        {
            break;
        }
        
         int temp = arr[parentIndex];
         arr[parentIndex] = arr[minIndex];
         arr[minIndex] = temp;
        
         parentIndex = minIndex;
         leftchildIndex = (2 * parentIndex) + 1;
         rightchildIndex = (2 * parentIndex) + 2;
    }
    
    sortByRemove(arr,n,heapIndex-1);
    
    return;
}

void heapSort(int arr[], int n) {
    // Write your code
    if(n == 0)
    {
        return;
    }
    
    int heapIndex = createHeap(arr,n,1);
    
    sortByRemove(arr,n,heapIndex);
    
    return;
}
*/

int main()
{
    priority_queue<int> pq;

    pq.push(100);
    pq.push(21);
    pq.push(55);
    pq.push(1);
    pq.push(10);

    cout<<"size "<<pq.size()<<endl;
    cout<<"Top "<<pq.top()<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}