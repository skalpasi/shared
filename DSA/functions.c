#include <stdio.h>
#include <stdlib.h>
#define SIZE(a) sizeof(a) / sizeof(a[0]);
int add(int a, int b);
// void swap(int *a, int *b);
void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}
void printArray(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
}
int *fun(int n) {
  // Static array
  // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int *p = a;
  // Dynamic Array
  int *p = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }
  return p;
}
int main() {
  // int x, y, z;
  // x = 10;
  // y = 5;
  // z = add(x, y);
  // printf("Before swappign %d %d", x, y);
  // swap(&x, &y);
  // printf("\nAfter swapping %d %d", x, y);
  // int a[5] = {1, 2, 3, 4, 5};
  // printf("\n%lu", sizeof(a));
  // int *A = fun(y);
  // for (int j = 0; j < y; j++) {
  //   printf("\n%d", A[j]);
  // }
  // int arr[] = {1, 2, 3, 4, 5, 6};
  // int n = SIZE(arr);
  // printArray(arr, n);
  int a = 5;
  int b = 10;
  swap(a, b);
  printf("%d %d", a, b);
  return 0;
}
int add(int a, int b) { return a + b; }
// void swap(int *a, int *b) {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }
