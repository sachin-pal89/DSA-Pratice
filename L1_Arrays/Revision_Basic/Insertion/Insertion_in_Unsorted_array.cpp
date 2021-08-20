#include<bits/stdc++.h>
using namespace std;

/* a[] : Array containing elements
   n : current size of array
   key : Element to be inserted
   capacity : Max size of array
*/
int InUnArr(int a[],int n,int key,int capacity)
{
      if(n >= capacity)
      {cout<<"Can't insert \n";
      return n;
      }

      a[n] = key;
      return n+1;
}

int main()
{   
    int cap,key,n;
    cout<<"\nEnter Capacity of Array ";
    cin>> cap;
    cout<<"\nEnter the element to be inserted ";
    cin>>key;
    cout<<"\nEnter No.of elemnts present in array ";
    cin>>n;

    int a[cap];
    cout<<"\nEnter the element of array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"\nBefore insertion \n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    int x;
    cout<<"\nAfter Insertion \n";
    x = InUnArr(a,n,key,cap);
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

}