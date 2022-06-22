#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
    		return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
    		return INT_MIN;
	return stack->array[stack->top--];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[n];
	struct Stack* stack = createStack(n);
	for(int i = 0; i<n; i++){
    		scanf("%d",&arr[i]);
	}
	for(int i = 0; i<n; i++){
    		push(stack, arr[i]);
	}
	for(int i = 0; i<n; i++){
    		printf("%d ", pop(stack));
	}
	return 0;
}
