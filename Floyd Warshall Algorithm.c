#include <stdio.h>

#define V 4
#define INF 1000000  
void floydWarshall(int dist[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,     5,     INF,   10},
        {INF,   0,     3,     INF},
        {INF,   INF,   0,     1},
        {INF,   INF,   INF,   0}
    };

    floydWarshall(graph);
    printSolution(graph);

    return 0;
}
