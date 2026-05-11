#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], indegree[MAX], queue[MAX];
int front = 0, rear = 0;

int main() {
    int n, i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree of each vertex
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++) {
            indegree[i] += adj[j][i];
        }
    }

    // Insert vertices with indegree 0 into queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Ordering: ");

    while(front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for(i = 0; i < n; i++) {
            if(adj[vertex][i] == 1) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }

        count++;
    }

    if(count != n) {
        printf("\nGraph contains a cycle.\n");
    }

    return 0;
}

/*
OUTPUT
Enter number of vertices: 6
Enter adjacency matrix:
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 1 1 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0

Topological Ordering: 0 1 2 3 4 5
*/
