#include<bits/stdc++.h>
using namespace std;

// Code for Using binary search in sorted and rotated array
int BinarySearchSR(int a[],int key,int low,int high)
{

    if(low<=high)
    {
        int mid = low + (high - low)/2;

        if(a[mid] == key)
        return mid;

        if(a[low] <= a[mid]) // if a[low.....mid] is sorted 
        {
            if(key >= a[low] && key < a[mid])
            return BinarySearchSR(a,key,low,mid-1);

            return BinarySearchSR(a,key,mid+1,high);
        }

        // Then a[mid+1.....high] will be sorted 
        if(key > a[mid] && key <= a[high])
        return BinarySearchSR(a,key,mid+1,high);

        return BinarySearchSR(a,key,low,mid-1);
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

    int reInd = BinarySearchSR(a,key,0,n-1);
    if(reInd == -1)
    cout<<"\nElement not found \nPlease give valid input ";
    else
    cout<<"\nElement was found at index "<<reInd<<"\n";
}