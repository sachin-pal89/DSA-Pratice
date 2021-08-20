// For finding out the largets sum of subarray
#include<bits/stdc++.h>
using namespace std;

int Max_subarray(int a[],int n)
{
    int curr_sum=a[0],max_sum=a[0];
    for(int i=1;i<n;i++)
    {   
        /* Condition where we have both +ve & -ve numbers
          curr_sum += a[i];

        if(curr_sum>max_sum)
           max_sum=curr_sum;

        if(curr_sum<0)
           curr_sum=0;
        */

       // If question also contain array with all -ve element
       curr_sum= max(a[i],curr_sum+a[i]);
       max_sum= max(max_sum,curr_sum);
    }
    return max_sum;
}
int main()
{
    int n;
    cout<<"\nEnter the size of an array: ";
    cin>>n;
    
    int a[n];
    cout<<"\nEnter the elements of an array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"\nMaximum sum of subarray is: "<<Max_subarray(a,n);
    return 0;
}