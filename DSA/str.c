#include <stdio.h>
#include <string.h>
int main() {
  char a[] = "sarthak abc bcd efg";
  // printf("%lu\n", strlen(a));
  // char name[10];
  // printf("Enter your name: ");
  // // scanf("%s", &name);
  // gets(name);
  // printf("Your name: %s", name);
  int len = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    len++;
  }
  printf("%d", len);
  return 0;
}
