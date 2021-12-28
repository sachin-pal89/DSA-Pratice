#include <iostream>
#include<queue>
using namespace std;

void print(int**edges,int n,int startV,bool* visit)
{
    //To maintain a queue for BFS traversal
    queue<int> vertices;
    
    //To enter the first element in queue
    vertices.push(startV);
    
    while(!vertices.empty())
    {
        // To get the current vertex
        int top = vertices.front();
        cout<<top<<" ";
        vertices.pop();
        
        // To traverse through all adjacent vertices
        for(int i = 0; i < n; i++)
        {
            // If the current vertices is equal to i
            if(i == top)
            {
                continue;
            }
            
            // If their an edge between current vertex and i vertex
            if(edges[top][i] == 1)
            {
                // If the i vertex is already visited
                if(visit[i])
                {
                    continue;
                }
                
                // To push the vertex for futher traversal
                vertices.push(i);
                
                // To maintain the record as it is traversed
                visit[i] = true;
            }
        }
        
        // To keep record as it is traversed
        visit[top] = true;
    }
    
    // To print the vertices which are not connected in graph
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            print(edges,n,i,visit);
        }
    } 

    return;
}

int main() {
    
    // No of vertices and edges
    int n,e;
    cin>>n>>e;
    
    // Adjancey Matrix
    int**edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    
    //To Take the edges
    for(int i = 0; i < e; i++)
    {
        int FVertex,SVertex;
        cin>>FVertex>>SVertex;
        
        edges[FVertex][SVertex] = 1;
        edges[SVertex][FVertex] = 1;
    }
    
    // To keep record of visited vertices
    bool*visit = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    
    // To print the vertices of graph
    print(edges,n,0,visit);

    // deleting all array and matrix
    for(int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    
    delete[] edges;
    delete[] visit;
    
    return 0;
}