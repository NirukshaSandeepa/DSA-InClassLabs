#include <bits/stdc++.h>
using namespace std;
 
#define numVertices 6 // Number of vertices in the graph

int parent[numVertices]; // Global array to store constructed MST

int minimumKey(int key[], bool MSTSet[]) // Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
{
    int min = INT_MAX, minimumIndex; // Initialize min value
 
    for (int v = 0; v < numVertices; v++)
        if (MSTSet[v] == false && key[v] < min)
            min = key[v], minimumIndex = v; // Update minimum value and index of minimum value
 
    return minimumIndex;
}

void primsMST(int graph[numVertices][numVertices]) // Function to construct and print MST for a graph represented using adjacency matrix representation
{
    bool MSTSet[numVertices]; // Array to represent set of vertices included in MST

    int key[numVertices]; // Key values used to pick minimum weight edge in cut
 
    for (int i = 0; i < numVertices; i++)
        key[i] = INT_MAX, MSTSet[i] = false;
 
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
   
    parent[0] = 0; // First node is the root of MST
 
    for (int count = 0; count < numVertices - 1; count++) {
         
        int u = minimumKey(key, MSTSet); // Pick the minimum key vertex from the set of vertices not yet included in MST
 
        MSTSet[u] = true; // Add the picked vertex to the MST Set
 
        for (int v = 0; v < numVertices; v++){
            if (graph[u][v] && MSTSet[v] == false && graph[u][v] < key[v]){ // Update key value and parent index of the adjacent vertices of the picked vertex. Consider only those vertices which are not yet included in MST
                parent[v] = u, key[v] = graph[u][v];
            } 
        }
    }

}
 
int main()
{
    // Adjacency Matrix for the graph
    int graph[numVertices][numVertices] = { { 0,3,0,0,0,1 },
                                            { 3,0,3,1,10,0 },
                                            { 0,2,0,3,0,5 },
                                            { 0,1,3,0,5,0 },
                                            { 0,10,0,5,0,4 },
                                            { 1,0,5,0,4,0 } };
                    
    primsMST(graph); // Function call to construct MST

    // Print the constructed MST
    cout<<"Minimum Spannig Tree:\n";
    cout << " Edge \tWeight\n";
    for (int i = 1; i < numVertices; i++)
        cout << parent[i] << " - " << i << " \t  " << graph[i][parent[i]] << " \n";

    return 0;
}
