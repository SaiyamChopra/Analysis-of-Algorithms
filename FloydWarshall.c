#include <stdio.h>
#define INF 99
int V;

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int graph[V][V];
    printf("Enter the elements of the matrix(IF NO WEIGHT ENTER 99):\n");
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)  
        { 
            if (i == j) 
                graph[i][j] = 0; 
            else { 
            printf("Enter the weight for edge (%d -> %d): ", i + 1, j + 1); 
            scanf("%d", &graph[i][j]);    
            } 
        }
    }
    floydWarshall(graph);
    return 0;
}