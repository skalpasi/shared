#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void reverse(char *pass) {
  for (int i = 0; i < strlen(pass) / 2; i++) {
    char temp = pass[i];
    pass[i] = pass[strlen(pass) - i - 1];
    pass[strlen(pass) - i - 1] = temp;
  }
}
int main() {
  char a[] = "abcadcba";
  char s[strlen(a)];
  char d[strlen(a)];
  memcpy(s, a, strlen(a));
  strcpy(d, a);
  // printf("%lu\n", strlen(a));
  // char name[10];
  // printf("Enter your name: ");
  // scanf("%s", &name);
  // gets(name);
  // printf("Your name: %s", name);
  int len = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    len++;
  }
  printf("%d", len);
  printf("\n--%s-- --%s-- --%s--\n", a, s, d);
  reverse(a);
  if (strcmp(a, d) == 0)
    printf("palindrome");
  return 0;
}
