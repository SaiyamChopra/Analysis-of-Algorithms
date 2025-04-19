#include <stdio.h>
#define INF 99999
#define MAX 100  // Set a reasonable maximum number of vertices

int graph[MAX][MAX];
int selected[MAX];

void primsAlgorithm(int n) {
    int ne = 0;
    int min, x = 0, y = 0;

    // Initialize all selected to 0 (false)
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    selected[0] = 1;  // Start from vertex 0

    printf("\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n");

    while (ne < n - 1) {
        min = INF;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("Edge %d: (%d - %d) cost: %d\n", ++ne, x, y, graph[x][y]);
        selected[y] = 1;
    }
}

int main() {
    int n;
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("Too many vertices! Please enter %d or fewer.\n", MAX);
        return 1;
    }

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    primsAlgorithm(n);

    return 0;
}
