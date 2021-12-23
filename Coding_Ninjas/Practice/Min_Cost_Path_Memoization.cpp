// Memoization Approach

#include<iostream>
#include<climits>
using namespace std;

/*
3 4
3 4 1 2
2 1 8 9
4 7 8 1
*/

// To return the result using memoization
int minCost(int **input, int m, int n, int i, int j, int **output)
{
    // If we go out of bound
    if(i >= m || j >= n)
    {
        return INT_MAX;
    }

    // If we reach to the (m-1,n-1)th element
    if(i == m-1 && j == n-1)
    {
        return input[i][j];
    }

    // If we reach to an element for which we already have minimum cost path in ouput array
    if(output[i][j] != -1)
    {
        return output[i][j];
    }

    // To go through all possible path and get the minimum cost path to reach the last element

    // For rightward motion
    int rightPath = minCost(input,m,n,i,j+1,output);

    // For downward motion
    int downPath = minCost(input,m,n,i+1,j,output);

    // For diagona motion
    int diagonalPath = minCost(input,m,n,i+1,j+1,output);

    // To store the minimum cost path from current element by adding its cost with the minimum cost path among all three.
    int ans = input[i][j] + min(rightPath,min(downPath,diagonalPath));

    // To save it in record for future view
    output[i][j] = ans;

    // return the cost path
    return output[i][j];
}

int minCostPath(int **input, int m, int n)
{
    // Creating an output array to keep record of cost Path
    int **output = new int*[m];

    for(int i = 0; i < m; i++)
    {
       output[i] = new int[n];

       // Intializing the output array with -1
       for(int j = 0; j < n; j++)
       {
           output[i][j] = -1;
       }
    }

   return minCost(input,m,n,0,0,output);
}

int main()
{
   int **arr,m,n;

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

   cout<<"Minimum Cost Path: "<<minCostPath(arr,m,n);

   return 0;
}