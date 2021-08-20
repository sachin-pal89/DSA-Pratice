#include<bits/stdc++.h>
using namespace std;

// Code for Linear Search using two counters
int LinSearCou(int a[],int n,int key)
{
    int left = 0;
    int right = n-1;
    int re = -1;

    while(left<=right)
    {
        if(a[left] == key)
        return left;
        
        if(a[right] == key)
        return right;

        left++;
        right--;
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

    int reInd = LinSearCou(a,n,key);
    if(reInd == -1)
    cout<<"\nElement not found \nPlease give valid input ";
    else
    cout<<"\nElement was found at index "<<reInd<<"\n";
}