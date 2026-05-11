/*
Algorithm KruskalMST(Graph, V, E)
Input: 
    Graph with V vertices and E edges
Output: 
    Minimum Cost Spanning Tree

1. Start
2. Read number of vertices V
3. Read number of edges E
4. Store all edges with source, destination, and weight
5. Sort all edges in increasing order of weight
6. Initialize parent array so each vertex is its own parent
7. For each edge in sorted order:
       a. Find parent of source vertex
       b. Find parent of destination vertex
       c. If parents are different:
              i. Include edge in MST
             ii. Add edge weight to total cost
            iii. Union the two sets
8. Repeat until (V - 1) edges are selected
9. Print edges of MST
10. Print total minimum cost
11. Stop
*/

// C-CODE

#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

void sortEdges(struct Edge edges[], int E) {
    int i, j;
    struct Edge temp;

    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int V, E;
    int i, count = 0, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter source destination and weight of each edge:\n");

    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    sortEdges(edges, E);

    for (i = 0; i < V; i++) {
        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < E && count < V - 1; i++) {
        int srcParent = find(edges[i].src);
        int destParent = find(edges[i].dest);

        if (srcParent != destParent) {
            printf("%d -- %d == %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            totalCost += edges[i].weight;
            unionSet(srcParent, destParent);
            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}

/*
OUTPUT
Enter number of vertices: 4
Enter number of edges: 5
Enter source destination and weight of each edge:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Edges in Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10

Minimum Cost = 19
*/
