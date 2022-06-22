#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
    		return;
	queue->rear = (queue->rear + 1)% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
    		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}
int front(struct Queue* queue)
{
	if (isEmpty(queue))
    		return INT_MIN;
	return queue->array[queue->front];
}
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
    		return INT_MIN;
	return queue->array[queue->rear];
}

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int StackisFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int StackisEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if (StackisFull(stack))
    		return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if (StackisEmpty(stack))
    		return INT_MIN;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (StackisEmpty(stack))
    		return INT_MIN;
	return stack->array[stack->top];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	struct Stack* stack = createStack(n);
	struct Queue* queue = createQueue(n);
	for(int i = 0; i<n; i++){
    		int x = 0;
    		scanf("%d", &x);
    		enqueue(queue, x);
	}
	int golgappa[n];
	for(int i = 0; i<n; i++){
    		scanf("%d", &golgappa[i]);
	}
	for(int i = n-1; i>=0; i--){
    		int x = golgappa[i];
    		push(stack, x);
	}
	int counter=n*n;
	while(counter-->0)
	{
    		if((!StackisEmpty(stack)) && front(queue)==peek(stack)){
        		dequeue(queue);
        		pop(stack);
    		}
    		else{
        			if(!isEmpty(queue)){
            			int x = dequeue(queue);
            			enqueue(queue,x);
        			}
        			else{
            			printf("%d",0);
				return 0;
    			}
		}
	}
	int ans = 0;
	while(!isEmpty(queue)){
    		dequeue(queue);
    		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
