// Dynamic Programming approach

#include<iostream>
#include<climits>
using namespace std;

/*
3 4
3 4 1 2
2 1 8 9
4 7 8 1
*/

int minCostPath(int **input, int m, int n)
{
    // To fill the minimum cost for the positon on left of last element :- traversal from (right to left)
    for(int j = n-2; j >=0; j--)
    {
        input[m-1][j] += input[m-1][j+1];
    }

    // To fill the minimum cost for the positon upward of last element :- traversal from (down to up)
    for(int i = m-2; i >=0; i--)
    {
        input[i][n-1] += input[i+1][n-1];
    }

    // To fill up all the element which are in diagonal and on other row && column to last element
    for(int i = m-2; i>=0; i--)
    {
        for(int j = n-2; j>=0; j--)
        {
            input[i][j] += min(input[i+1][j+1], min(input[i][j+1], input[i+1][j]));
        }
    }

    return input[0][0];
}

int main()
{
    int **arr, m, n;

    cin>>m>>n;
    
    arr = new int*[m];

    for(int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Minimum Cost Path: "<<minCostPath(arr,m,n)<<endl;

    return 0;
}