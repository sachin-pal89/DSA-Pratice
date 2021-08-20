#include<bits/stdc++.h>
using namespace std;

void Reversing(int arra[],int num)
{
      for(int i=0;i<(num/2);i++)     // Time Complexity is T(n) = O(n)
      {  
          int temp = arra[i];
          arra[i] = arra[num-(i+1)];
          arra[num-(i+1)] = temp;
      }
}

void Printing(int arra[],int num)
{
    for(int i=0;i<num;i++)
    {
        cout<<arra[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    Reversing(a, n);
    Printing(a,n);
    return 0;
}