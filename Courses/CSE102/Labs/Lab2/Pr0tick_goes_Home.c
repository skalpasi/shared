// Import Libraries
#include <stdio.h>
#include <stdlib.h>

int** matrix;

// Main Function
int solve(int currRow, int currCol, int targetRow, int targetCol) {
    // Check if Out of Bounds
    if (currRow < 0 || currRow > targetRow || currCol < 0 || currCol > targetCol) {
        return 0;
    }
    // Check if Target is Reached
    if (currRow == targetRow && currCol == targetCol) {
        return 1;
    }
    // Check if Current is 0
    if (matrix[currRow][currCol] == 0) {
        return 0;
    }
    else {
        // Call for Neighbours
        return solve(currRow + 1, currCol, targetRow, targetCol) + solve(currRow, currCol + 1, targetRow, targetCol);
    }
}

int main(int argc, char *argv[]) {
    // Take n, m, x, y as Input
    int n, m, x, y;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &x);
    scanf("%d", &y);
    // Initialize Matrix
    matrix = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(m, sizeof(int));
    }
    // Take Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (matrix[x-1][y-1] == 0 || matrix[n-1][m-1] == 0 || matrix[0][0] == 0) {
        printf("0");
        return 0;
    }
    // Print Result
    printf("%d\n", solve(0, 0, x-1, y-1)*solve(x-1, y-1, n-1, m-1));
    // Free Memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    return 0;
}