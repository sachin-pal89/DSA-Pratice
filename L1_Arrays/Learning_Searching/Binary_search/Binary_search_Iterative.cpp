#include<bits/stdc++.h>
using namespace std;

// Code for Iterative Binary Serach
int BinarySearchI(int a[],int key,int low,int high)
{
    while(low<=high)
    {
        int mid = low + (high - low)/2;

        if(a[mid] == key)
        return mid;

        if(a[mid] < key)
        low = mid + 1;

        else
        high = mid -1;
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

    int reInd = BinarySearchI(a,key,0,n-1);
    if(reInd == -1)
    cout<<"\nElement not found \nPlease give valid input ";
    else
    cout<<"\nElement was found at index "<<reInd<<"\n";
}