#include<bits/stdc++.h>
using namespace std;

// Code for Recursive Binary Search
int BinarySearchR(int a[],int key,int low,int high)
{
    if(low<=high)
    {
        int mid = low + (high-low)/2;

        if(a[mid] == key )
        return mid;

        if(a[mid] < key)
        return BinarySearchR(a,key,mid+1,high);

        else
        return BinarySearchR(a,key,low,mid-1);
    }

    return -1;
}

int main()
{
    int n,key;
    cout<<"\nEnter the no.of element int the array ";
    cin>>n;

    int a[n];
    cout<<"\nEnter the elements of the array ";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"\nEnter the number to be found ";
    cin>>key;

    int reInd = BinarySearchR(a,key,0,n-1);
    if(reInd == -1)
    cout<<"\nElement not found \nPlease give valid input ";
    else
    cout<<"\nElement was found at index "<<reInd<<"\n";
}