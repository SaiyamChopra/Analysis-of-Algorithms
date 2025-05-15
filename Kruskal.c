#include <stdio.h>
#define MAX 10

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];
Edge edges[MAX];

// Function to find the root (parent) of a vertex
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two subsets
void unionSets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    parent[root_i] = root_j;
}

// Function to sort edges based on weight
void sortEdges(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm Implementation
void kruskal(int n, int e) {
    int mst_cost = 0, edge_count = 0;

    // Initialize parent array
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(e); // Step 1: Sort edges by weight

    printf("Selected Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        if (find(edges[i].u) != find(edges[i].v)) { // Step 2: Check for cycle
            printf("%d - %d (Weight: %d)\n", edges[i].u, edges[i].v, edges[i].weight);
            mst_cost += edges[i].weight;
            unionSets(edges[i].u, edges[i].v);
            edge_count++;
        }
        if (edge_count == n - 1) // Stop when MST has n-1 edges
            break;
    }

    printf("\nMinimum Cost of MST: %d\n", mst_cost);
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (format: u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal(n, e);

    return 0;
}