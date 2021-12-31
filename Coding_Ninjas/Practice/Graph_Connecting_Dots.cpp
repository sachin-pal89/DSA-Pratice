#include <iostream>
#include <vector>
using namespace std;

bool checkCycle(vector<vector<char>> &board, int n, int m, bool** visit, int startr, int startc, int row , int column, int k)
{
    // if we get out of bound
    if(row < 0 || column < 0 || row == n || column == m)
    {
        return false;
    }
    
    // since this character is been visited
    visit[row][column] = true;
    
    // if the current element is adjacent with the starting element and k+1 >= 4 then we found the path
    if(k+1 >= 4 && ((startr == row && startc == column-1) || (startr == row && startc == column+1) || (startr == row-1 && startc == column) || (startr == row+1 && startc == column)))
    {
        return true;
    }
    
    bool status = false;
    char curr = board[startr][startc];
    
    // for leftward motion
    if(column != 0 && !visit[row][column-1] && board[row][column-1] == curr)
    {
        status = status || checkCycle(board,n,m,visit,startr,startc,row,column-1,k+1);
    }
    
    // for rightward motion
    if(column != m-1 && !visit[row][column+1] && board[row][column+1] == curr)
    {
        status = status || checkCycle(board,n,m,visit,startr,startc,row,column+1,k+1);
    }
    
    // for upward motion
    if(row != 0 && !visit[row-1][column] && board[row-1][column] == curr)
    {
        status = status || checkCycle(board,n,m,visit,startr,startc,row-1,column,k+1);
    }
    
    // for downward motion
    if(row != n-1 && !visit[row+1][column] && board[row+1][column] == curr)
    {
        status = status || checkCycle(board,n,m,visit,startr,startc,row+1,column,k+1);
    }
    
    // if curr element is not in path then set it as unvisited
    if(!status)
    {
        visit[row][column] = false;
    }
    
    return status;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    
    // To keep record of visited element in the path
    bool** visit = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = new bool[m];
        for(int j = 0; j < m; j++)
        {
            visit[i][j] = false;
        }
    }
    
    bool ans = checkCycle(board,n,m,visit,0,0,0,0,0);
    
    // if from first element we got the answer
    if(ans)
    {
        return true;
    }
    
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // if element not visited start finding path from here
            if(!visit[i][j])
            {
                ans = checkCycle(board,n,m,visit,i,j,i,j,0);
            }
            
            // if path found then return true
            if(ans)
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}