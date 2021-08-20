#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{   
    cout<<"Enter the elements in array \n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

// Linear Search
int lsearch(int a[],int n,int ele)
{   
    for(int i=0;i<n;i++)
    {
        if(a[i] == ele)
        {
            return i;
        }
    }

     return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of array \n";
    cin>>n;
    
    int a[n];
    seta(a,n);

    int ele;
    cout<<"Enter the element to be search \n";
    cin>>ele;

    cout<<ele<<" Found at index "<<lsearch(a,n,ele)<<"\n";
    return 0;
}