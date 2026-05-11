/*
Algorithm Dijkstra(Graph, V, source)
Input: A weighted graph represented using an adjacency matrix Graph[V][V]
Output: Shortest distance from source vertex to all other vertices

1. Start
2. Read the number of vertices V
3. Read the adjacency matrix Graph[V][V]
4. Read the source vertex
5. Initialize:
       dist[i] = INFINITY for all vertices
       visited[i] = false for all vertices
6. Set dist[source] = 0
7. Repeat V-1 times:
       Select the unvisited vertex u with minimum dist[u]
       Mark u as visited
       For each vertex v:
            If v is not visited AND
               Graph[u][v] is not 0 AND
               dist[u] + Graph[u][v] < dist[v]
            Then
               dist[v] = dist[u] + Graph[u][v]
8. Display the shortest distances from source vertex
9. Stop
*/

// C-CODE

#include <stdio.h>

#define MAX 100
#define INF 99999

int minDistance(int dist[], int visited[], int V)
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == 0 && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[MAX][MAX], int V, int source)
{
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (int i = 0; i < V; i++)
    {
        printf("To vertex %d = %d\n", i, dist[i]);
    }
}

int main()
{
    int V;
    int graph[MAX][MAX];
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, V, source);

    return 0;
}

/*
OUTPUT
Enter number of vertices: 5
Enter adjacency matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Enter source vertex: 0

Shortest distances from vertex 0:
To vertex 0 = 0
To vertex 1 = 10
To vertex 2 = 50
To vertex 3 = 30
To vertex 4 = 60
*/
