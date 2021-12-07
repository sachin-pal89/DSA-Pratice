#include<iostream>
#include<queue>
using namespace std;

void HeapSort(int* arr, int n)
{
     priority_queue<int, vector<int>, greater<int>> pq;

     for(int i = 0; i < n; i++)
     {
         pq.push(arr[i]);
     }

     int j = 0;
     while(!pq.empty())
     {
         arr[j] = pq.top();
         pq.pop();
         j++;
     }
}

int main()
{
    int a[] = {1,4,22,4,56,89,23,55,34,66,12,34,65,11,56,32,55,6,67,89};

    int size = sizeof(a) / sizeof(a[0]);

    HeapSort(a,size);

    cout<<"Sorted Array is: "<<endl;

    for(int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}