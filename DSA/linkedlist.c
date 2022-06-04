#include <stdio.h>
#include <stdlib.h>
// Linked List - [3,4]
// first      data  next    data  next
// (0x200) -> (3 | 0x221) -> (6 | NULL)
//  0x100    0x200          0x221
// every node contains a value and pointer
// to nextnode. 3 is at 0x200 and 4 is at 0x221
struct Node {
  int data;
  struct Node *next; // self referential struct
} *head = NULL, *current = NULL;
void append(struct Node *link, int item) {
  link = (struct Node *)malloc(sizeof(struct Node));
  link->data = item;
  link->next = NULL;
  current->next = link;
}
void display(struct Node *p) {
  printf("%d", p->next);
  while (p->next) {
    printf("%d", p->data);
    p = p->next;
  }
}
int main() {
  append(current, 10);
  // append(current, 20);
  // append(current, 30);
  // display(current);
  return 0;
}
