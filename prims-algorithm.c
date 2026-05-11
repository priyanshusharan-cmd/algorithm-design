/*
Algorithm PrimMST(Graph, V)
Input: A weighted undirected graph represented using an adjacency matrix Graph[V][V]
Output: Minimum Cost Spanning Tree and its total cost

1. Start
2. Read the number of vertices V
3. Read the adjacency matrix Graph[V][V]

4. Initialize:
       selected[V] = {false}
       edgeCount = 0
       selected[0] = true
       totalCost = 0

5. While edgeCount < V - 1
       Set minimum = INF

       For each vertex i from 0 to V-1
           If selected[i] is true
               For each vertex j from 0 to V-1
                   If selected[j] is false AND Graph[i][j] is not 0
                       If Graph[i][j] < minimum
                           minimum = Graph[i][j]
                           x = i
                           y = j

       Print edge x - y and its weight
       Add minimum to totalCost
       selected[y] = true
       edgeCount = edgeCount + 1

6. Print totalCost
7. Stop
*/

//C-CODE

#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int graph[MAX][MAX];
    int selected[MAX];
    int V, i, j, edgeCount = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 0; i < V; i++) {
        selected[i] = 0;
    }

    selected[0] = 1;

    printf("\nEdges in Minimum Cost Spanning Tree:\n");

    while(edgeCount < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for(i = 0; i < V; i++) {
            if(selected[i]) {
                for(j = 0; j < V; j++) {
                    if(!selected[j] && graph[i][j]) {
                        if(min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);

        totalCost += graph[x][y];
        selected[y] = 1;
        edgeCount++;
    }

    printf("\nTotal Minimum Cost = %d\n", totalCost);

    return 0;
}

/*
OUTPUT
Enter number of vertices: 4
Enter adjacency matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0

Edges in Minimum Cost Spanning Tree:
0 - 1 : 2
1 - 2 : 3
0 - 3 : 6

Total Minimum Cost = 11
*/
