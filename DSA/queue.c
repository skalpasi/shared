#include <stdio.h>
#include <stdlib.h>
struct Queue {
  int size;
  int front;
  int rear;
  int *Q;
} queue;
void enqueue(struct Queue *q, int item) {
  if (q->rear < q->size) {
    q->Q[++q->rear] = item;
  }
}
void dequeue(struct Queue *q) {
  if (q->rear != q->front) {
    printf("Dequeue -> %d\n", q->Q[++q->front]);
  }
}
void display(struct Queue q) {
  for (int i = q.front + 1; i <= q.rear; i++) {
    printf("%d ", q.Q[i]);
  }
  printf("\n");
}
int main() {
  queue.size = 10;
  queue.front = -1;
  queue.rear = -1;
  queue.Q = (int *)malloc(queue.size * sizeof(int));
  dequeue(&queue);
  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  enqueue(&queue, 40);
  enqueue(&queue, 50);
  dequeue(&queue);
  enqueue(&queue, 60);
  dequeue(&queue);
  enqueue(&queue, 70);
  display(queue);
  return 0;
}
