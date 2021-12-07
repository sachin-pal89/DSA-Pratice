#include<iostream>
using namespace std;

int Fibohelp(int n, int* a)
{
    // Base Case
    if(n <= 1)
    {
        return n;
    }

    // To check if the fibonacci term of nth index is present already or not
    if(a[n] != -1)
    {
        return a[n];
    }

    int first = Fibohelp(n-1, a);
    int second = Fibohelp(n-2, a);

    // To store there sum as fibonacci term for this index of n
    a[n] = first + second;

    // Thus once saved we should return this term
    return a[n];
}

int getFibo(int n)
{
    // Creating an Dynamic Array of size n+1 to maintain the fibonacci value for a unique term
    int* a = new int[n+1];

    // To intiate array a with -1 
    for(int i = 0; i <= n; i++)
    {
        a[i] = -1;
    }

    return Fibohelp(n, a);
}

int main()
{
    int n;
    cin>>n;

    cout<<getFibo(n)<<endl;
    return 0;
}