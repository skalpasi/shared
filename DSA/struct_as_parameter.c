#include <stdio.h>
struct Rectangle {
  int length;
  int breadth;
};
// Pass by value
// int area(struct Rectangle r) {
//   return r.length * r.breadth;
// }
// Pass by address
int area(struct Rectangle *r) {
  int area = r->length * r->breadth;
  return area;
}
void changeLength(struct Rectangle *r, int n) { r->length = n; }
void changeBreadth(struct Rectangle *r, int n) { r->breadth = n; }
int main() {
  struct Rectangle r = {5, 10};
  struct Rectangle *p = &r;
  printf("%d", area(p));
  changeLength(&r, 100);
  changeBreadth(&r, 50);
  printf("\n%d", area(&r));
  return 0;
}
