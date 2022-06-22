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


int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
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


int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
int main(){

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);

    struct Stack* st = createStack(n);

    int nextGreaterOnLeft[n];

    nextGreaterOnLeft[0] = -1;
    push(st,arr[0]);

    for(int i = 1;i<n;i++){
        while(isEmpty(st)==0 && peek(st)<=arr[i]){
            pop(st);
        }
        if(isEmpty(st)==1){
            nextGreaterOnLeft[i] = -1;
        }
        else{
            nextGreaterOnLeft[i] = peek(st);
        }
        push(st,arr[i]);
    }

    for(int i = 0;i<n;i++){
        if(nextGreaterOnLeft[i]==-1){
            printf("%d ",arr[i]);
        }
        else{
            printf("%d ",nextGreaterOnLeft[i]);
        }
    }
    printf("\n");
    return 0;
}
