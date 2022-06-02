#include <stdio.h>
void loop(int n) {
  if (n > 0) {
    printf("%d\n", n);
    loop(n - 1);
  }
}
int main() {
  loop(5);
  return 0;
}
