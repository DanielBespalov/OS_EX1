#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to find the vertex with minimum distance value
// from the set of vertices not yet included in the shortest path tree
int minDistance(long dist[], bool sptSet[], int V) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(long dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t\t %ld\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int src, int V) {
    long dist[V];    // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = LONG_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] <= INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

bool readGraph(int **graph, int V) {
    printf("Enter the adjacency matrix for the graph (%dx%d) or type 'exit' to quit:\n", V, V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char input[20];
            if (scanf("%s", input) != 1) {
                return false;
            }
            char *endptr;
            long value = strtol(input, &endptr, 10);
            if (*endptr != '\0' || value < 0 || value > INT_MAX) {
                return false;
            }
            graph[i][j] = (int)value;
        }
    }

    return true;
}

int **allocateGraph(int V) {
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    return graph;
}

void freeGraph(int **graph, int V) {
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    while (true) {
        int V;
        printf("Enter the number of vertices in the graph (or type 0 to exit): ");
        if (scanf("%d", &V) != 1 || V < 0 || V > INT_MAX) {
            fprintf(stderr, "Invalid number of vertices.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        if (V == 0) {
            break;
        }

        int **graph = allocateGraph(V);

        if (!readGraph(graph, V)) {
            printf("Failed to read the graph. Please try again.\n");
            freeGraph(graph, V);
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        // Run Dijkstra's algorithm from source vertex 0
        dijkstra(graph, 0, V);
        freeGraph(graph, V);
    }

    return 0;
}
