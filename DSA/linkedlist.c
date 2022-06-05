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
  int size;
  struct Node *next; // self referential struct
} *head = NULL, *last = NULL;

void display() {
  if (head == NULL)
    return;
  struct Node *it = head->next; // head->next has first node
  while (it) {
    printf("%d ", it->data);
    it = it->next;
  }
  printf("size %d\n", head->size);
}

void append(int item) {
  struct Node *link = (struct Node *)malloc(sizeof(struct Node));
  link->data = item;
  link->next = NULL;
  if (head == NULL) {
    head = (struct Node *)malloc(sizeof(struct Node));
    last = (struct Node *)malloc(sizeof(struct Node));
    head->next = link;
  }
  last->next = link;
  last = link;
  head->size++;
}

void insert(int index, int item) {
  if (head == NULL || index > head->size)
    return;
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (index == 0) {
    node->next = head->next;
    head->next = node;
  } else {
    struct Node *it = head->next;
    for (int i = 0; i < index - 1; i++) {
      it = it->next;
    }
    node->next = it->next;
    it->next = node;
  }
  node->data = item;
  if (index == head->size) {
    last = node;
  }
  head->size++;
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
  head->size++;
}

void delete (int index) {
  if (head == NULL || index >= head->size)
    return;
  struct Node *it = head->next;
  if (index == 0) {
    head->next = head->next->next;
    return;
  }
  for (int i = 0; i < index - 1; i++) {
    it = it->next;
  }
  it->next = it->next->next;
  head->size--;
}

void insertFirst(int item) { insert(0, item); }

void deleteFirst(int item) { delete (0); }

void clear() { head = NULL; }

int main() {
  append(15);
  display();
  insert(1, 4);
  display();
  delete (1);
  display();
  append(32);
  display();
  insertIfSorted(33);
  display();
  return 0;
}
