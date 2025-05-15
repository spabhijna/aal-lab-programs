#include <stdio.h>

#define V 5
#define E 7

struct Edge {
    int u, v, w;
};

int parent[V];

int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

void sortEdges(struct Edge edges[]) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (edges[i].w > edges[j].w) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[]) {
    int count = 0;
    sortEdges(edges);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].w);
            unionSet(u, v);
            count++;
        }
    }
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    kruskal(edges);
    return 0;
}
