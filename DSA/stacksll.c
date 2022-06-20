#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *top = NULL;

void push(int value) {
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value; // assign value to the node
  if (top == NULL) {
    newNode->next = NULL;
  } else {
    newNode->next = top; // Make the node as top
  }
  top = newNode; // top always points to the newly created node
  printf("Node is Inserted\n\n");
}

int pop() {
  if (top == NULL) {
    printf("Stack Underflow\n");
    return -1;
  } else {
    struct Node *temp = top;
    int temp_data = top->data;
    top = top->next;
    free(temp);
    return temp_data;
  }
}

void display() {
  if (top == NULL) {
    printf("\nStack Underflow\n");
  } else {
    printf("The stack is \n");
    struct Node *temp = top;
    while (temp->next != NULL) {
      printf("%d--->", temp->data);
      temp = temp->next;
    }
    printf("%d--->NULL\n\n", temp->data);
  }
}

int main() { return 0; }
