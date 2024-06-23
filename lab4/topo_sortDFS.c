#include <stdio.h>
#include <stdlib.h>

void DFS(int u, int n, int a[n][n], int s[], int *j, int res[]) {
    s[u] = 1;
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            DFS(v, n, a, s, j, res);
        }
    }
    (*j)++;
    res[*j] = u;
}

void topological_order(int n, int a[n][n]) {
    int s[n];
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }
    int j = -1;
    int res[n];

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            DFS(i, n, a, s, &j, res);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");
}

int main() {
    int adjacency_matrix[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0}
    };
    int num_vertices = 5;
    topological_order(num_vertices, adjacency_matrix);
    return 0;
}
