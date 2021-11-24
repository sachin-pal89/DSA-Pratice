#include<iostream>
#include<queue>
using namespace std;

void kSortArray(int arr[],int n,int k)
{
    priority_queue<int> pq;

    for(int i=0; i<k ;i++)
    {
        pq.push(arr[i]);
    }

    int j = 0;
    for(int i = k; i < n ; i++)
    {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty())
    {
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    int a[] = {12,15,7,6,9};
    kSortArray(a,5,3);

    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}