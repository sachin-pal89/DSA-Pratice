/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/

#include<iostream>
using namespace std;

int helper(int input[], int length, int output[10000][50],int ans[], int k, int ind, int row)
{
    int sum = 0;
    for(int i=0; i<ind; i++)
    {
        sum += ans[i];
    }

    if(sum == k)
    {
        output[row][0] = ind;

        for(int i=1; i<=output[row][0]; i++)
        {
            output[row][i] = ans[i-1];
        }

        return row+1;
    }

    if(length == 0)
    {
        return row;
    }

    int result1 = helper(input+1,length-1,output,ans,k,ind,row);

    ans[ind] = input[0];

    int result2 = helper(input+1,length-1,output,ans,k,ind+1,result1);

    return result2;
}

int subsetSumToK(int input[], int length, int output[10000][50], int k)
{
    int ans[10];

    return helper(input,length,output,ans,k,0,0);
}

int main()
{
    int input[20],length,output[10000][50],k;

    cin>>length;

    for(int i=0; i<length; i++)
    {
        cin>>input[i];
    }

    cin>>k;

    int size = subsetSumToK(input,length,output,k);

    for(int i=0; i<size; i++)
    {
        for(int j=1; j<=output[i][0]; j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

