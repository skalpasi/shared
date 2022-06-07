#include <stdio.h>
#include <stdlib.h>
struct Node {
  struct Node *prev;
  int data;
  int size;
  struct Node *next;
} *head = NULL, *last = NULL;
void append(int item) {
  struct Node *link = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = last;
  link->data = item;
  link->prev = temp;
  link->next = NULL;
  if (head == NULL) {
    head = (struct Node *)malloc(sizeof(struct Node));
    last = (struct Node *)malloc(sizeof(struct Node));
    head->next = link;
    link->prev = NULL;
  }
  last->next = link;
  head->size++;
}
void display() {
  if (head == NULL)
    return;
  struct Node *it = head->next;
  while (it) {
    printf("%d ", it->data);
  }
}
int main() {
  append(10);
  append(20);
  display();
  return 0;
}
