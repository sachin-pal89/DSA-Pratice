#include <iostream>
#include<vector>
using namespace std;


vector<int> getPath(int** edges, int n, int StartV, int EndV, int* visit)
{
    // Since the vertex get accessed
    visit[StartV] = true;
    
    // If we reached to end vertex
    if(StartV == EndV)
    {
        vector<int> path;
        path.push_back(StartV);
        return path;
    }
    
    vector<int> ans;

    // To traverse through all connected verteices to find the path
    for(int i = 0; i < n; i++)
    {
        // If i is the current vertex
        if(i == StartV)
        {
            continue;
        }
        
        // If their is an edge between the StartV and i vertices
        if(edges[StartV][i] == 1)
        {
            // If i vertex already visited
            if(visit[i])
            {
                continue;
            }
            
            // To search end Vertex from i vertex
            ans = getPath(edges,n,i,EndV,visit);
            
            // If the end vertex is found
            if(!ans.empty())
            {
                ans.push_back(StartV);
                return ans;
            }
        }
    }
    
    return ans;
}

void findPath(int** edges, int n, int StartV, int EndV)
{
    // To keep record of visited items
    int* visit = new int[n];
    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    
    // To store the resultant path
    vector<int> path = getPath(edges,n,StartV,EndV,visit);

    // To print the desired path obatin
    for(int i = 0; i < path.size(); i++)
    {
        cout<<path.at(i)<<" ";
    }
    
}

int main() {
    
    // No of vertices and edges
    int n,e;
    cin>>n>>e;
    
    //Adjancey matrix
    int** edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    
    //Taking edges in graph
    for(int i = 0; i < e; i++)
    {
        int FVertex,SVertex;
        cin>>FVertex>>SVertex;
        
        edges[FVertex][SVertex] = 1;
        edges[SVertex][FVertex] = 1;
    }
    
    //To get the starting and ending vertices
    int StartV,EndV;
    cin>>StartV>>EndV;
    
    findPath(edges,n,min(StartV,EndV),max(StartV,EndV));
    
    return 0;
}