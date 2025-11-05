#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index, v;
    for (v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];
    int i;

    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    int count;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        int v;
        for (v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source %d\n", src);
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void main() {
    clrscr();
    int graph[V][V] = {{0, 10, 0, 30, 100},
                       {10, 0, 50, 0, 0},
                       {0, 50, 0, 20, 10},
                       {30, 0, 20, 0, 60},
                       {100, 0, 10, 60, 0}};

    dijkstra(graph, 0);
}
