// DFS Traversal in Graphs
#include<iostream>
using namespace std;

// DFS Traversal and printing the vertices
void print(int** edges, int n, int startV, bool* visit)
{
    // To print the starting vertex and set is as visited
    cout<<startV<<" ";
    visit[startV] = true;

    // To traverse on each adjacent vertex
    for(int i = 0; i < n; i++)
    {
        // If the same vertex comes
        if(i == startV)
        {
            continue;
        }

        //If theirs an edge between the vertices
        if(edges[startV][i] == 1)
        {
            // If the i vertex is already been traversed
            if(visit[i])
            {
                continue;
            }

            // Move to the adjacent vertex to print its adjacent vertices first
            print(edges,n,i,visit);
        }
    }

    return;
}

int main()
{
    //No.of vertices
    int n;

    //No.of edges
    int e;

    cin>>n>>e;

    //Adjancey Matrix
    int **edges = new int*[n];

    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];

        //Intializing Adjancey martix with zero
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // To get the edges in graph
    for(int i = 0; i < e; i++)
    {
        int FVertex,SVertex;

        cin>>FVertex>>SVertex;

        edges[FVertex][SVertex] = 1;
        edges[SVertex][FVertex] = 1;
    }

    // Array for keep record of vertices already visited
    bool* visit = new bool[n];

    for(int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    // To print the graph through DFS Traversal
    print(edges,n,0,visit);

    return 0;
}