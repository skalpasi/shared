#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define TOP -1
struct Stack {
  int size;
  int top;
  int *ptr;
};
void enqueue(struct Stack *nq, int item) {
  if (nq->top < nq->size - 1) {
    nq->ptr[++nq->top] = item;
  }
}
void dequeue(struct Stack *nq, struct Stack *dq) {
  if (dq->top == -1) {
    if (nq->top == -1)
      return;
    int j = 0;
    for (int i = nq->top; i >= 0; i--) {
      dq->ptr[j] = nq->ptr[i];
      j++;
    }
    nq->top = TOP;
    dq->top = j - 1;
  }
  printf("Dequeue -> %d\n", dq->ptr[dq->top]);
  dq->top--;
}
void display(struct Stack nq, struct Stack dq) {
  for (int i = dq.top; i >= 0; i--) {
    printf("%d ", dq.ptr[i]);
  }
  for (int i = 0; i <= nq.top; i++) {
    printf("%d ", nq.ptr[i]);
  }
}
int main() {
  struct Stack nq = {SIZE, TOP};
  struct Stack dq = {SIZE, TOP};
  nq.ptr = (int *)malloc(SIZE * sizeof(int));
  dq.ptr = (int *)malloc(SIZE * sizeof(int));
  dequeue(&nq, &dq);
  enqueue(&nq, 10);
  enqueue(&nq, 20);
  enqueue(&nq, 30);
  enqueue(&nq, 40);
  enqueue(&nq, 50);
  dequeue(&nq, &dq);
  enqueue(&nq, 60);
  dequeue(&nq, &dq);
  enqueue(&nq, 70);
  display(nq, dq);
  return 0;
}
