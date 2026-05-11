/*
Algorithm FloydWarshall(Graph, V)
Input: A weighted graph represented using an adjacency matrix Graph[V][V]
Output: Shortest distance between every pair of vertices

1. Start
2. Read the number of vertices V
3. Read the adjacency matrix Graph[V][V]
4. For each vertex k from 0 to V-1
5.     For each vertex i from 0 to V-1
6.         For each vertex j from 0 to V-1
7.             If Graph[i][k] + Graph[k][j] < Graph[i][j]
8.                 Update Graph[i][j] = Graph[i][k] + Graph[k][j]
9. Print the shortest distance matrix
10. Stop
*/

// C-CODE

#include <stdio.h>

#define INF 99999

int main() {
    int n, i, j, k;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter the adjacency matrix:\n");
    printf("Use %d for INF (no direct edge)\n", INF);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Floyd Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
OUPUT
Enter the number of vertices: 4
Enter the adjacency matrix:
Use 99999 for INF (no direct edge)

0 5 99999 10
99999 0 3 99999
99999 99999 0 1
99999 99999 99999 0

Shortest distance matrix:
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF 0
*/
