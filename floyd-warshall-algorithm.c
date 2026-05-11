/*
Algorithm FloydWarshall(Graph, V)
Input: A 2D array Graph[V][V] representing edge weights, where V is the number of vertices.
Output: A 2D array dist[V][V] containing the shortest paths between all pairs of vertices.

1. Initialize dist[V][V]
2. For i from 0 to V-1:
       For j from 0 to V-1:
           dist[i][j] = Graph[i][j]
3. For k from 0 to V-1 (Intermediate vertex):
       For i from 0 to V-1 (Source vertex):
           For j from 0 to V-1 (Destination vertex):
               If dist[i][k] + dist[k][j] < dist[i][j]:
                   dist[i][j] = dist[i][k] + dist[k][j]
4. Return dist
*/

#include <stdio.h>

#define INF 99999 // Representing infinity for unconnected nodes

// Function to run Floyd-Warshall and print the result
void floydWarshall(int n, int graph[n][n]) {
    int dist[n][n];

    // Step 1: Initialize the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Core relaxation loop
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If the path through intermediate vertex k is shorter, update it
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the final shortest distance matrix
    printf("\nShortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Prompt user for the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Variable Length Array (VLA) supported in C99 and later
    int graph[n][n];

    // Prompt user for the adjacency matrix
    printf("\nEnter the adjacency matrix row by row.\n");
    printf("(Note: Use %d to represent Infinity for nodes that are not directly connected)\n", INF);
    
    for (int i = 0; i < n; i++) {
        printf("Enter values for row %d (separated by spaces): ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run the algorithm
    floydWarshall(n, graph);

    return 0;
}

/*
OUTPUT
Enter the number of vertices in the graph: 4

Enter the adjacency matrix row by row.
(Note: Use 99999 to represent Infinity for nodes that are not directly connected)

Enter values for row 1 (separated by spaces): 0 5 99999 10
Enter values for row 2 (separated by spaces): 99999 0 3 99999
Enter values for row 3 (separated by spaces): 99999 99999 0 1
Enter values for row 4 (separated by spaces): 99999 99999 99999 0

Shortest distances between every pair of vertices:
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0
*/
