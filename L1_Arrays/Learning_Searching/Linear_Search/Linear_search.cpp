#include<bits/stdc++.h>
using namespace std;

// Code for Linear search
int LiSearch(int a[],int n,int key)
{
    int i;
    int re = -1;
    for(i=0;i<n;i++)
    {
        if(a[i] == key)
        re = i;
    }
    
    return re;
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

    int reInd = LiSearch(a,n,key);
    if(reInd == -1)
    cout<<"\nElement not found \nPlease give valid input ";
    else
    cout<<"\nElement was found at index "<<reInd<<"\n";

    return 0;
}