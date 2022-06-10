// Import Libraries
#include <stdio.h>
#include <stdlib.h>
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

// Main Function
// flag - 0 for a, 1 for b, 2 for c
int solve(int matrix[][3], int level, int flag, int n) {
    if (level == n) {
        return 0;
    }
    if (flag == 0){
        return max(matrix[level][1] + solve(matrix, level + 1, 1, n), matrix[level][2] + solve(matrix, level + 1, 2, n));
    }
    else if (flag == 1){
        return max(matrix[level][0] + solve(matrix, level + 1, 0, n), matrix[level][2] + solve(matrix, level + 1, 2, n));
    }
    else{
        return max(matrix[level][0] + solve(matrix, level + 1, 0, n), matrix[level][1] + solve(matrix, level + 1, 1, n));
    }
}

int main() {
    // Take n
    int n;
    scanf("%d", &n);
    // Initialize Matrix
    int matrix[n][3];
    // Take Input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Solve
    printf("%d\n", max(
                    max(
                        solve(matrix, 0, 0, n), 
                        solve(matrix, 0, 1, n)
                        ), 
                        solve(matrix, 0, 2, n)
                    )
        );
    return 0;
}