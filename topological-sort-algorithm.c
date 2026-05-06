/*
Algorithm TopologicalSort(Graph, V)
Input: A directed graph represented by an adjacency matrix Graph[V][V] where V is the number of vertices.
Output: A topological ordering of the vertices, or an error if the graph contains a cycle.

1. Initialize an array inDegree[V] to all 0s.
2. For each vertex u from 0 to V-1:
       For each vertex v from 0 to V-1:
           If Graph[u][v] == 1:
               Increment inDegree[v] by 1
3. Initialize an empty queue Q.
4. For each vertex i from 0 to V-1:
       If inDegree[i] == 0:
           Enqueue i into Q
5. Initialize a counter visited_count = 0
6. Initialize an array topOrder[V] to store the result.
7. While Q is not empty:
       Dequeue vertex u from Q
       Store u in topOrder[visited_count]
       Increment visited_count by 1
       For each adjacent vertex v of u (where Graph[u][v] == 1):
           Decrement inDegree[v] by 1
           If inDegree[v] == 0:
               Enqueue v into Q
8. If visited_count != V:
       Print "Graph contains a cycle! Topological sort is not possible."
9. Else:
       Print topOrder array as the topological sorting of the graph.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform Topological Sort
void topologicalSort(int n, int graph[n][n]) {
    int inDegree[n];
    
    // Step 1: Initialize in-degrees to 0
    for(int i = 0; i < n; i++) {
        inDegree[i] = 0;
    }

    // Step 2: Calculate in-degrees for all vertices
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Step 3 & 4: Queue to store vertices with 0 in-degree
    int queue[n];
    int front = 0, rear = 0;

    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topOrder[n];

    // Step 7: Process the queue
    while(front < rear) {
        int u = queue[front++];
        topOrder[count++] = u; // Add to topological order

        // Decrease in-degree of all adjacent vertices
        for(int v = 0; v < n; v++) {
            if(graph[u][v] == 1) {
                inDegree[v]--;
                // If in-degree becomes zero, add it to queue
                if(inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // Step 8 & 9: Check for cycles and print result
    if(count != n) {
        printf("\nGraph contains a cycle! Topological sort is not possible.\n");
    } else {
        printf("\nTopological Ordering: ");
        for(int i = 0; i < n; i++) {
            printf("%d ", topOrder[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Ask user for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Variable Length Array (VLA) for the graph
    int graph[n][n];

    // Ask user for the adjacency matrix
    printf("\nEnter the adjacency matrix row by row (use 1 for an edge, 0 for no edge):\n");
    for(int i = 0; i < n; i++) {
        printf("Enter values for row %d (separated by spaces): ", i);
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run the topological sort algorithm
    topologicalSort(n, graph);

    return 0;
}
