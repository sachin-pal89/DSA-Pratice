#include <iostream>
#include <vector>
using namespace std;

bool checkPath(vector<vector<char>> &board, int n, int m, bool** visit, int row, int column, string ans)
{
    // If we found all the character in CODINGNINJA
    if(ans.empty())
    {
        return true;
    }
    
    // If we get out of bounds
    if(row < 0 || column < 0 || row == n || column == m)
    {
        return false;
    }
    
    // As we visited this index during traversal so to keep record of it
    visit[row][column] = true;
    
    bool status = false;
    
    // for Upward left motion
    if(row != 0 && column != 0 && !visit[row-1][column-1] && board[row-1][column-1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row-1,column-1,ans.substr(1));
    }
    
    // for upward motion
    if(row != 0 && !visit[row-1][column] && board[row-1][column] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row-1,column,ans.substr(1));
    }
    
    // for upward right motion
    if(row != 0 && column != m-1 && !visit[row-1][column+1] && board[row-1][column+1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row-1,column+1,ans.substr(1));
    }
    
    // for left motion
    if(column != 0 && !visit[row][column-1] && board[row][column-1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row,column-1,ans.substr(1));
    }
    
    // for right motion
    if(column != m-1 && !visit[row][column+1] && board[row][column+1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row,column+1,ans.substr(1));
    }
    
    // for downward left motion
    if(row != n-1 && column != 0 && !visit[row+1][column-1] && board[row+1][column-1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row+1,column-1,ans.substr(1));
    }
    
    // for downward motion
    if(row != n-1 && !visit[row+1][column] && board[row+1][column] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row+1,column,ans.substr(1));
    }
    
    // for downward right motion
    if(row != n-1 && column != m-1 && !visit[row+1][column+1] && board[row+1][column+1] == ans[1])
    {
        status = status || checkPath(board,n,m,visit,row+1,column+1,ans.substr(1));
    }
    
    // if status is false and not satisfy any above case to find path
    if(!status)
    {
       // if current caharacter is last element of the path
       if(ans[1] == '\0')
       {
           status = true;
       }
       else // if not the last element but also not in desired path
       {
          visit[row][column] = false;
       }
      
    }
    
    return status;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    
    // To keep record of visited character
    bool** visit = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = new bool[m];
        for(int j = 0; j < m; j++)
        {
            visit[i][j] = false;
        }
    }
    
    bool statusPath = false;
    
    // To find the C in board
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // C is the starting point and thus traverse through it's index i.e. i && j
            if(board[i][j] == 'C')
            {
               statusPath = checkPath(board,n,m,visit,i,j,"CODINGNINJA"); 
            }
            
            // If we found the desired path
            if(statusPath)
            {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);

    return 0;
}