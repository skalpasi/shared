#include <stdio.h>
#include <stdlib.h>
struct Stack {
  int size;
  int top;
  int *ptr;
} st;
int isEmpty(struct Stack stack) { return (stack.top == -1); }
int isFull(struct Stack stack) { return (stack.top == stack.size - 1); }
void push(struct Stack *stack, int item) {
  if (isFull(*stack)) {
    printf("Stack Overflow!\n");
    return;
  }
  stack->top++;
  stack->ptr[stack->top] = item;
  printf("%d", stack->top);
}
int pop(struct Stack *stack) {
  if (isEmpty(*stack)) {
    printf("Stack Underflow!\n");
    return -1;
  }
  return stack->ptr[stack->top--];
}
void display(struct Stack stack) {
  for (int i = stack.top; i >= 0; i--) {
    printf("%d ", stack.ptr[i]);
  }
}
int peek(struct Stack stack, int index) {
  if (index > stack.top || index < 0) {
    printf("Index not found!");
    return -1;
  }
  return stack.ptr[index];
}
int main() {
  st.size = 5;
  st.top = -1;
  st.ptr = (int *)malloc(st.size);
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  push(&st, 50);
}
