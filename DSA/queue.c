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
    q->front++;
  }
}
void display(struct Queue q) {
  for (int i = q.front + 1; i <= q.rear; i++) {
    printf("%d  ", q.Q[i]);
  }
  printf("\n");
  // for (int i = 0; i < q.size; i++) {
  //   if (i == q.front) {
  //     printf("F ");
  //   } else if (i == q.rear) {
  //     printf("R ");
  //   } else {
  //     printf("  ");
  //   }
  //   printf("  ");
  // }
  // printf("\n");
}
int main() {
  queue.size = 10;
  queue.front = -1;
  queue.rear = -1;
  queue.Q = (int *)malloc(queue.size * sizeof(int));
  while (1) {
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
      int item;
      scanf("%d", &item);
      enqueue(&queue, item);
    } else if (choice == 2) {
      dequeue(&queue);
    }
    display(queue);
  }
  return 0;
}
