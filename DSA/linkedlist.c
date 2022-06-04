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
} *head = NULL, *current;
void append(struct Node *p, int item) {
  p->data = item;
  p->next = NULL;
  p = current;
}
void display(struct Node *p) {
  while (p->next) {
    printf("%d", p->data);
    p = p->next;
  }
}
int main() {
  head = (struct Node *)malloc(sizeof(struct Node));
  current = head;
  append(current, 10);
  append(current, 20);
  append(current, 30);
  display(head);
  return 0;
}
