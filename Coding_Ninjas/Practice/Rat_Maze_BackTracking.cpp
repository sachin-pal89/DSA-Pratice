#include<bits/stdc++.h>
using namespace std;

int maze[20][20];

void print(int** ans, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }
    cout<<endl;
}

void RatMaze(int maze[][20], int n, int** ans, int row, int column)
{
   // If Reached to the end point
   if(row == n-1 && column == n-1)
   {
       ans[row][column] = 1;
       print(ans,n);

       // To reset value to 0 for backtracking
       ans[row][column] = 0;
       return;
   }

   // If the range becomes out of maze
   if(row == -1 || row == n || column == -1 || column == n)
   {
       return;
   }
   // If 0 is present at the position in maze then to return since 0 is a block in path
   else if(maze[row][column] == 0)
   {
       return;
   }
   // If in we already visited this position in the current path
   else if(ans[row][column] == 1)
   {
       return;
   }

   // To add current element in ans matrix
   ans[row][column] = 1;

   // For Top traversal
   RatMaze(maze,n,ans,row-1,column);

   // For Down traversal
   RatMaze(maze,n,ans,row+1,column);

   // For Left traversal
   RatMaze(maze,n,ans,row,column-1);

   // For Right traversal
   RatMaze(maze,n,ans,row,column+1);

   // For resetting value of the current element to backTrack
   ans[row][column] = 0;

   return;
}

void getPath(int maze[][20], int n)
{
    int** ans = new int*[n];
    for(int i = 0; i < n; i++)
    {
        ans[i] = new int[n];
    }
    
    // To intialize the ans matrix with 0
    for(int i = 0; i < n; i++)
    {
       memset(ans[i],0,n*sizeof(int));
    }

    RatMaze(maze,n,ans,0,0);
    return;
}

int main()
{
    int n;
    cin>>n;

    memset(maze,0,20*20*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           cin>>maze[i][j];
        }
    }

    getPath(maze,n);

    return 0;
}