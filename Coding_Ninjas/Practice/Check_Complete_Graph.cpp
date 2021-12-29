#include <iostream>
using namespace std;

bool ConnectDFS(int** edges, int n, int start,bool* visit)
{
    // Current vertex is visited
    visit[start] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(i == start)
        {
            continue;
        }
        
        if(edges[start][i] == 1)
        {
            if(visit[i])
            {
                continue;
            }
            
            ConnectDFS(edges,n,i,visit);
        }
    }
    
    //To check if any vertex is not visited then retrn false as it is not connected graph
    for(int i = 0; i < n; i++)
    {
        // if i vertex is not visited than it is a non connected graph
        if(!visit[i])
        {
            return false;
        }
    }
    
    return true;
}

bool checkConnect(int** edges, int n)
{
    //To keep record of visited vertices
    bool* visit = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    
    return ConnectDFS(edges,n,0,visit);
}

int main() {
    
    // No of vertices and edges
    int n,e;
    cin>>n>>e;
    
    //Adjancey Matrix
    int** edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    
    //To take edges in the graph
    for(int i = 0; i < e; i++)
    {
        int FVertex,SVertex;
        cin>>FVertex>>SVertex;
        
        edges[FVertex][SVertex] = 1;
        edges[SVertex][FVertex] = 1;
    }
    
    bool ans = checkConnect(edges,n);
    
    if(ans)
    {
       cout<<"true";
    }
    else
    {
       cout<<"false";
    }
    
    return 0;
}