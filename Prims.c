#include <stdio.h>
#define INF 999

int graph[5][5];     // Adjacency matrix of the graph
int selected[5] = {0}; // To track visited vertices
int i, j;             // Loop control variables
int f = 0, t = 1, min; // For storing false, true, and minimum value
int x, y, ne = 0;      // Selected edge x-y, ne for number of edges in MST

void primsAlgorithm(int n) {
    selected[0] = 1;  // Start from vertex 0

    while (ne < n - 1) {
        min = INF;
        x = 0;
        y = 0;

        // Step 2: Find the smallest edge
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) { // Only consider unvisited nodes
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("Edge %d: (%d - %d) cost: %d\n", ++ne, x, y, graph[x][y]);
        selected[y] = 1; // Mark vertex as visited
    }
}

int main() {
    printf("Enter the adjacency matrix (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) graph[i][j] = INF; // Replace 0 with infinity for Prim's logic
        }
    }

    printf("\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n");
    primsAlgorithm(5);

    return 0;
}
