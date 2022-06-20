#include <stdio.h>
void updateNum(int *num) { *num = 20; }
int main() {
  int num = 10;
  printf("before updating: %d\n", num);
  updateNum(&num);
  printf("after updating: %d\n", num);
}
