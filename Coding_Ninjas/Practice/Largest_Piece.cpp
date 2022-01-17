#include <iostream>
#include <vector>
using namespace std;

int Piece(vector<vector<int>> &cake, int n, int row, int column, bool** visit)
{
    // if we reached out of bound
    if(row < 0 || column < 0 || row == n || column == n)
    {
        return 0;
    }
    
    // as current element is visited in the path
    visit[row][column] = true;
    
    int ans = 0;
    
    // for leftward motion
    if(column != 0 && !visit[row][column-1] && cake[row][column-1] == 1)
    {
        ans += Piece(cake,n,row,column-1,visit);
    }
    
    // for rightward motion
    if(column != n-1 && !visit[row][column+1] && cake[row][column+1] == 1)
    {
        ans += Piece(cake,n,row,column+1,visit);
    }
    
    // for upward motion
    if(row != 0 && !visit[row-1][column] && cake[row-1][column] == 1)
    {
        ans += Piece(cake,n,row-1,column,visit);
    }
    
    // for downward motion
    if(row != n-1 && !visit[row+1][column] && cake[row+1][column] == 1)
    {
        ans += Piece(cake,n,row+1,column,visit);
    }
    
    // maximum lenght + the current element included
    return ans + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    
    // to  keep record of visited elements
    bool** visit = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = new bool[n];
        for(int j = 0; j < n; j++)
        {
            visit[i][j] = false;
        }
    }
    
    int size = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            // if we found 1 in cake and also it is not been explored before
            if(cake[i][j] == 1 )
            {
                size = max(size,Piece(cake,n,i,j,visit));
            }
        }
    }
    
    return size;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}