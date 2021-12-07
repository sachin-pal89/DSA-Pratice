#include<bits/stdc++.h>
using namespace std;

int board[11][11];

// To check if position is suitable to insert
bool placePossible(int n,int row,int column)
{
    // For same column
    for(int i = row-1; i >= 0 ; i--)
    {
        if(board[i][column] == 1) 
        {
            return false;
        }
    }
    
    // For Upper left Diagonal
    for(int i = row-1, j = column-1; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    // For Upper Right Diagoal
    for(int i = row-1, j = column+1; i>=0 && j<n; i--,j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }

    return true;

}

// Print the correct solution
void print(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
    }

    cout<<endl;
}

// Find the NQueen using BackTracking
void NQueen(int n, int row)
{
   // If we get an required matrix
   if(row == n)
   {
       print(n);
       return;
   }

   // To fill all possible positions
   for(int i = 0; i < n; i++)
   {
       // If its suitable position then insert it
       if(placePossible(n,row,i))
       {
           board[row][i] = 1;

           // Look for next row to fill
           NQueen(n,row+1);

           // BackTrack by setting it to its original state
           board[row][i] = 0;
       }
   }

   return;
}

int main()
{
    int n;
    cin>>n;

    // Intailiazing all values of board with 0s
    memset(board,0,11*11*sizeof(int));

    NQueen(n,0);
    return 0;
}