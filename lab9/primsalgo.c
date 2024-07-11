#include <stdio.h>
#define INF 9999

void prim(int n, int cost[n][n]) {
    int s[n]; // To track which vertices are in the MST
    int d[n]; // Shortest distance from source to each vertex
    int p[n]; // Parent array to store the MST

    int i, j, min, source, sum = 0, k = 0;

    // Step 1: Choose a source vertex with minimum edge going out of it
    min = INF;
    source = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    // Step 2: Initialization
    for (i = 0; i < n; i++) {
        s[i] = 0; // Not yet included in MST
        d[i] = cost[source][i]; // Initialize distances from source
        p[i] = source; // Parent of each vertex in MST
    }

    // Step 3: Add source to the MST
    s[source] = 1;

    // Step 4: Find MST
    for (i = 1; i < n; i++) {
        // Find vertex u such that d[u] is minimum and u not in s
        min = INF;
        int u = -1;
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        // Add the edge (u, p[u]) to the MST
        printf("(%d, %d) ", u, p[u]);
        sum += cost[u][p[u]];
        s[u] = 1; // Add u to the MST

        // Update d[] and p[] for adjacent vertices of u
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && cost[u][j] < d[j]) {
                d[j] = cost[u][j];
                p[j] = u;
            }
        }
    }

    // Step 5: Check if MST exists
    if (sum >= INF) {
        printf("\nSpanning tree does not exist\n");
    } else {
        printf("\nThe cost of the Minimum Spanning Tree is %d\n", sum);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nMinimum Spanning Tree edges:\n");
    prim(n, cost);

    return 0;
}
