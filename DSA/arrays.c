#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int a[] = {1, 2, 3, 4, 5};               // static array
  int *p = (int *)malloc(5 * sizeof(int)); // dynamic memory using heap
  printf("%d %d", sizeof(p), sizeof(*p));
  for (int i = 0; i < 5; i++)
    p[i] = i + 1;
  printf("\narray before increasing size - \n");
  for (int i = 0; i < 5; i++)
    printf("%d ", p[i]);
  // how to increase size of array?
  // only dynamic arrays can be increased
  // we have pointer p pointing to a dynamic array
  int *q = (int *)malloc(10 * sizeof(int)); // create array of new size
  memcpy(q, p, 5 * sizeof(int));
  free(p);
  p = q;
  q = NULL;
  printf("\narray after increasing size - \n");
  for (int i = 0; i < 10; i++)
    printf("%d ", p[i]);
  unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  printf("%u,%u, %u", x + 3, *(x + 3), *(x + 2) + 3);
  return 0;
}
