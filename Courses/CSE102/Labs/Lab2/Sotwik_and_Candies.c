// Import Libraries
#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

int main(int argc, char *argv[]) {
    // Take n
    int n;
    scanf("%d", &n);
    // Initialize Array
    int *array = (int*)calloc(n, sizeof(int));
    // Take Input, maintain sumofArray
    int sumOfArray = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sumOfArray += array[i];
    }
    // If Even Print Directly
    if (sumOfArray % 2 == 0) {
        printf("%d\n", sumOfArray);
    }
    // If Odd Print sum-1
    else {
        printf("%d\n", sumOfArray - 1);
    }
    return 0;
}