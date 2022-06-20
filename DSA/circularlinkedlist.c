#include <stdio.h>
#include <stdlib.h>

// Circular Linked List - [3,4]
// head      data  next    data  next
// (0x200) -> (3 | 0x221) -> (6 | 0x100)
//  0x100    0x200          0x221
// every node contains a value and pointer
// to next node. 3 is at 0x200 and 4 is at 0x221

struct Node {
  int data;
  struct Node *next; // self referential struct
} *head = NULL, *last = NULL;

void display() {
  if (head == NULL)
    return;
  struct Node *it = head; // head->next has first node
  int c = 0;
  while (it != head || c == 0) {
    printf("%d ", it->data);
    it = it->next;
    c = 1;
  }
}

void append(int item) {
  struct Node *link = (struct Node *)malloc(sizeof(struct Node));
  link->data = item;
  link->next = head;
  if (head == NULL) {
    head = (struct Node *)malloc(sizeof(struct Node));
    last = (struct Node *)malloc(sizeof(struct Node));
    head = link;
  }
  last->next = link;
  last = link;
}

void insert(int index, int item) {
  if (head == NULL)
    return;
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = item;
  if (index == 0) {
    node->next = head;
    head = node;
  } else {
    struct Node *it = head;
    for (int i = 0; i < index - 1; i++) {
      it = it->next;
    }
    if (!it->next) {
      last = node;
    }
    node->next = it->next;
    it->next = node;
  }
}

void insertIfSorted(int item) {
  if (head == NULL)
    return;
  struct Node *it = head->next;
  while (1) {
    if (it->next == NULL || it->data <= item && it->next->data >= item) {
      break;
    }
    it = it->next;
  }
  struct Node *link = (struct Node *)malloc(sizeof(struct Node));
  link->data = item;
  link->next = it->next;
  it->next = link;
}

void delete (int index) {
  if (head == NULL)
    return;
  struct Node *it = head;
  if (index == 0) {
    head = head->next;
    return;
  }
  for (int i = 0; i < index - 1; i++) {
    it = it->next;
  }
  it->next = it->next->next;
}

void insertFirst(int item) { insert(0, item); }

void deleteFirst(int item) { delete (0); }

void clear() { head = NULL; }

int main() {
  append(15);
  append(32);
  insert(2, 100);
  display();
  return 0;
}
