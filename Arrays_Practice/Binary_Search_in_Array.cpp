#include<bits/stdc++.h>
using namespace std;

void seta(int a[],int n)
{
    cout<<"Enter the elements of array \n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
 
// ONLY FOR SORTED ARRAY
int Bsearch(int a[],int low,int high,int ele)
{
  if(low<=high)
  {
    int mid = low + (high-low)/2;
    if(a[mid]==ele)
    {
      return mid;
    }

    if(a[mid]<ele)
    {
      return Bsearch(a,mid+1,high,ele);
    }
    
    else{
      return Bsearch(a,low,mid-1,ele);
    }
  }
  return -1;
}
int main()
{
    int n;
    cout<<"Enter the no. of element in an array \n";
    cin>>n;

    int a[n];
    seta(a,n);

    int ele;
    cout<<"Enter the element to be searched \n";
    cin>>ele;

    cout<<ele<<" was found at index "<<Bsearch(a,0,n-1,ele);
    return 0;
}