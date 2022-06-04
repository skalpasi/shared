#include <math.h>
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
  // lenght of string
  int len = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    len++;
  }
  // palindrom
  char s[strlen(a)];
  char d[strlen(a)];
  memcpy(s, a, strlen(a));
  strcpy(d, a);
  printf("%d", len);
  reverse(a);
  if (strcmp(a, d) == 0)
    printf("palindrome");
  // check repeating char using bitwise
  int bits = 0;
  for (int i = 0; a[i] != '\0'; i++) {
    int ascii = a[i] - 97;
    int ptr = 1;
    ptr <<= ascii;
    if (ptr & bits) {
      printf("%c is repeating\n", a[i]);
    } else {
      bits |= ptr;
    }
  }
  // string anagram
  char p[] = "dbca";
  char q[] = "abcd";
  int t = 0;
  for (int i = 0; i < strlen(p); i++) {
    t ^= p[i] ^ q[i];
  }
  if (!t)
    printf("anagram");
  // permutations of string
  // todo
  return 0;
}
