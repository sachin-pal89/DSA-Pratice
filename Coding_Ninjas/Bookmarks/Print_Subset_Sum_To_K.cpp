/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

#include<iostream>
using namespace std;

void helper(int input[], int length, int ans[], int k, int ind)
{
    int sum = 0;
    for(int i=0; i<ind; i++)
    {
        sum += ans[i];
    }

    if(sum == k)
    {
        for(int i=0; i<ind; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(length == 0)
    {
        return;
    }

    helper(input+1,length-1,ans,k,ind);

    ans[ind] = input[0];

    helper(input+1,length-1,ans,k,ind+1);

    return;
}

void printSubsetSumToK(int input[],int length, int k)
{
    int ans[20];

    helper(input,length,ans,k,0);
}

int main()
{
    int input[20],length,k;

    cin>>length;

    for(int i=0; i<length; i++)
    {
        cin>>input[i];
    }

    cin>>k;

    printSubsetSumToK(input,length,k);

    return 0;
}