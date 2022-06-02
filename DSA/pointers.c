#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person {
  char name[10];
  int age;
};
int main() {
  int aa = 10;
  int *p = &aa;
  printf("%d\n", *p); // accesing variable from stack memory
  // to allocate memroy in heap, we use malloc function
  int *pp = (int *)malloc(5 * sizeof(int)); // allocates memoery for 5 integers
  printf("%d\n", *pp);
  int a[5] = {1, 2, 3, 4, 5};
  int *n, *m;
  n = &a[3];
  m = a;
  printf("%d\n", n[1]);
  int *array = (int *)malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++) {
    array[i] = i;
  }
  for (int j = 0; j < 5; j++)
    printf("%d\n", array[j]);
  struct Person per;
  struct Person *po = &per;
  printf("%lu", sizeof(struct Person));
  // per->name = "sarthak"; // Array type char[10] is not assignable
  strcpy(po->name, "sarthak");
  po->age = 18;
  printf("\n%s is %d yo. he is lives in stack.", po->name, (*po).age);
  // dynamic struct
  struct Person *perro = (struct Person *)malloc(sizeof(struct Person));
  perro->age = 20;
  strcpy(perro->name, "cyka");
  printf("\n%s is %d yo. he is lives in heap.", perro->name, perro->age);
  return 0;
}
