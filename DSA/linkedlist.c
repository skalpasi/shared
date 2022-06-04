#include <stdio.h>
#include <stdlib.h>
// Linked List - [3,4]
// first      data  next    data  next
// (0x200) -> (3 | 0x221) -> (6 | NULL)
//  0x100    0x200          0x221
// every node contains a value and pointer
// to next node. 3 is at 0x200 and 4 is at 0x221
struct Node {
  int data;
  struct Node *next; // self referential struct
} *head = NULL, *last = NULL;
void append(int item) {
  struct Node *link = (struct Node *)malloc(sizeof(struct Node));
  link->data = item;
  link->next = NULL;
  if (head == NULL) {
    last = (struct Node *)malloc(sizeof(struct Node));
    head = link;
    head->next = link;
  }
  last->next = link;
  last = link;
}
void insert(int index, int item) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (index == 0) {
    node->next = head;
    head = node;
  } else {
    struct Node *it = head;
    for (int i = 0; i < index - 1; i++) {
      it = it->next;
    }
    // todo
  }
  node->data = item;
}
void delete (int index) {
  // this function will
  // delete the node
}
void display() {
  struct Node *it = head;
  while (it) {
    printf("%d ", it->data);
    it = it->next;
  }
}
int main() {
  append(10);
  append(20);
  append(40);
  append(50);
  // insert(0, 100);
  insert(2, 100);
  display();
  return 0;
}
