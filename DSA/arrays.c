#include <stdio.h>
struct Rectangle {
  int length;
  int breadth;
};
struct Complex {
  int real;
  int imag;
};
struct Student {
  int rollno;
  char name[25];
  char dept[3];
  char address[50];
  int phone;
};
int main() {
  struct Rectangle r;
  r.length = 10;
  r.breadth = 5;
  int area = r.length * r.breadth;
  printf("Area of rectangle is %d", area);
}
