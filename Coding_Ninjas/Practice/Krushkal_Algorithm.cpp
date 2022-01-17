#include <bits/stdc++.h>
using namespace std;

// edges class to save the edges and the weight of the edges
class edges
{
    public:
       int fvertex;
       int svertex;
       int weight;
    
    // Default Constructor
    edges(){}

    // for storing the edges and their weight
    edges(int fvertex, int svertex, int weight)
    {
        this->fvertex = fvertex;
        this->svertex = svertex;
        this->weight = weight;
    }
    
};

// to check if adding this edges to MST would create a cycle or not
bool checkCycle(int fvertex, int svertex, int* parent)
{
    int i = fvertex;
    int j = svertex;
    
    // till we find the parent vertex of first vertex of our current edge
    while(parent[i] != i)
    {
        i = parent[i];
    }
    
    // till we find the parent vertex of second vertex of our current edge
    while(parent[j] != j)
    {
        j = parent[j];
    }
    
    // if parent of both vertices are the same then this edge can form cycle so return true
    if(i == j)
    {
        return true;
    }
    
    // we set the parent of max vertex as similar to that of min vertex;
    parent[max(i,j)] = min(i,j);
    
    // as no cycle is present so false
    return false;
}

// to check and create the MST by Krushkal algorithm
void getMST(int n, int e, int edgesCount, edges* input, edges* output, int* parent)
{
    // for mainting the index for MST
    int x = 0;
    
    // till we have edges less than n-1 as in MST we have n-1 edges only
    for(int i = 0; i < e && x < edgesCount; i++)
    {   
        // if the current edge does not form a cycle
        if(!checkCycle(input[i].fvertex, input[i].svertex, parent))
        {
             // saving fvertex of result as minimum of the two input vertices
             output[x].fvertex = min(input[i].fvertex, input[i].svertex);
            
             // saving svertex of result as maximum of the two input vertices
             output[x].svertex = max(input[i].fvertex, input[i].svertex);
            
             // the weight of the result would be the same
             output[x].weight = input[i].weight;
            
             // as one edge is added increse the edge count
             edgesCount++;
            
             // as one edge is added in MST
             x++;
        }
    }
}

// to sort the edges by weight the one with less weight comes first
bool sortEdges(edges fvertex, edges svertex)
{
        return (fvertex.weight < svertex.weight);
}

int main() {
    
    // No of vertices and edges
    int n,e;
    cin>>n>>e;
    
    //input array to store the edges
    edges input[e];
    
    //output array for MST
    edges output[n-1];
    
    for(int i = 0; i < e; i++)
    {
        int fvertex, svertex, weight;
        cin>>fvertex>>svertex>>weight;
        
        // creating an edge class
        edges obj(fvertex,svertex,weight);
        
        // storing it in input edge array
        input[i] = obj;
    }
    
    // sort the input array by weight
    sort(input, input+e, sortEdges);
    
    // to maintain the parent array
    int *parent  = new int[n];
    for(int i = 0; i < n; i++)
    {
        // by default its own value is thier parent
        parent[i] = i;
    }
    
    // to get the MST and store it in the output array
    getMST(n, e, n-1, input, output, parent);
    
    // printing the MST edges and their respective weights
    for(int i = 0; i < n-1 ; i++)
    {
        cout<<output[i].fvertex<<" "<<output[i].svertex<<" "<<output[i].weight<<endl;
    }
    
    return 0;
}