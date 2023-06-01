#include <iostream>
#include <stdio.h>
using namespace std;
#define INFINITY 9999
#define max 6

// Dijkstra's Algorithm for finding the shortest path from a single source to all other nodes in a graph
void dijkstra (int G[max][max],int n, int startnode){ 
    double average = 0; // Initialize average to 0
    int cost[max][max];   // cost matrix
    int time[max];    // array to store the shortest distance from startnode
    bool visited[max];    // array to track visited nodes

    // Initialize cost matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY; // If there is no edge between i and j, set cost to INFINITY
            else
                cost[i][j] = G[i][j]; // If there is an edge between i and j, set cost to the weight of the edge
        }
    }

    for (int i = 0; i < n; i++) {
        time[i] = cost[startnode][i];
        visited[i] = false;
    }

    time[startnode] = 0;
    visited[startnode] = true;

    int count = 1;
    while (count < n - 1) { 
        int mindistance = INFINITY; // Initialize mindistance to INFINITY
        int nextnode = 0; // Initialize nextnode to 0

        // Find the node with the minimum distance
        for (int i = 0; i < n; i++) {
            if (time[i] < mindistance && !visited[i]) { // If the node is not visited and the distance is less than the minimum distance
                mindistance = time[i];
                nextnode = i;
            }
        }

        visited[nextnode] = true;
        count++;

        // Update the distance array
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < time[i]) {
                    time[i] = mindistance + cost[nextnode][i];
                }
            }
        }
    }

    // Print the shortest distances from the startnode to all other nodes
    cout << "Shortest time from city " << startnode << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "City " << i << ": " << time[i] << endl;
        average += time[i];
    }
    cout << "Average time taken from city " << startnode <<" = " << average / (n-1) << endl;
    cout << "------------------------------------\n";
    
}

int main() {
    int G[max][max]={
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };
    int n=6;
    for(int i=0;i<n;i++){
        dijkstra(G,n,i);
    }
    return 0;
}
