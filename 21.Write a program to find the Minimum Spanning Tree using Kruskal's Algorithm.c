#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

typedef struct DSU {
    int* parent;
    int* rank;
} DSU;

DSU* createDSU(int V) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc(V * sizeof(int));
    dsu->rank = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
    return dsu;
}

int find(DSU* dsu, int x) {
    if (dsu->parent[x] != x)
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    return dsu->parent[x];
}

void unionSets(DSU* dsu, int x, int y) {
    int rootX = find(dsu, x);
    int rootY = find(dsu, y);
    if (rootX != rootY) {
        if (dsu->rank[rootX] < dsu->rank[rootY])
            dsu->parent[rootX] = rootY;
        else if (dsu->rank[rootX] > dsu->rank[rootY])
            dsu->parent[rootY] = rootX;
        else {
            dsu->parent[rootY] = rootX;
            dsu->rank[rootX]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskalMST(Graph* graph) {
    qsort(graph->edges, graph->E, sizeof(Edge), compareEdges);
    DSU* dsu = createDSU(graph->V);

    Edge* result = (Edge*)malloc((graph->V - 1) * sizeof(Edge));
    int e = 0, i = 0;

    while (e < graph->V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];
        int x = find(dsu, nextEdge.src);
        int y = find(dsu, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(dsu, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d : %d\n", result[i].src, result[i].dest, result[i].weight);

    free(result);
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}

void main() {
    clrscr();
    int V = 4, E = 5;
    Graph* graph = createGraph(V, E);

    graph->edges[0].src = 0; graph->edges[0].dest = 1; graph->edges[0].weight = 10;
    graph->edges[1].src = 0; graph->edges[1].dest = 2; graph->edges[1].weight = 6;
    graph->edges[2].src = 0; graph->edges[2].dest = 3; graph->edges[2].weight = 5;
    graph->edges[3].src = 1; graph->edges[3].dest = 3; graph->edges[3].weight = 15;
    graph->edges[4].src = 2; graph->edges[4].dest = 3; graph->edges[4].weight = 4;

    kruskalMST(graph);

    free(graph->edges);
    free(graph);
}
