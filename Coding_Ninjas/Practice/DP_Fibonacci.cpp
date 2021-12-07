#include<iostream>
using namespace std;

// Used Dynamic Programming which is a bottom - up Approach to get Fibonacci. Time Complexity - O(N)

// To return the nth term in fibonacci series
int getFibo(int n)
{
   // A Dynamic array of size n+1 for implementing the dynamic approach
   int* a = new int[n+1];

   // Setting the base conditions first
   a[0] = 0;
   a[1] = 1;

   // To set the term occuring at ith number in fibonacci series
   for(int i = 2; i <= n; i++)
   {
       a[i] = a[i-1] + a[i-2];
   }

   // The answer must be present at last nth index
   return a[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<getFibo(n)<<endl;
    return 0;
}