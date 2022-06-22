#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int MAX(int num1, int num2)
{
    return (num1 >= num2 ) ? num1 : num2;
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
    //printf("%d pushed to stack\n", item);
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
int main()
{
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    int jump_over[n];
    for(int i = 0; i<n; i++){
        jump_over[i] = 0;
    }
    struct Stack* stack = createStack(n);
    push(stack,0);
    for(int i = 1; i < n; i++){
        while(!isEmpty(stack) && arr[i] > arr[peek(stack)]){
            jump_over[peek(stack)] = i;
            pop(stack);
        }
        push(stack,i);
    }
    while(!isEmpty(stack)){
        jump_over[peek(stack)] = -1;
        pop(stack);
    }
    int max_xor[n];
    for(int i = 0; i<n; i++){
        max_xor[i] = 0;
    }
    int max = 0;
    long ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(jump_over[i] == -1){
            max_xor[i] = arr[i];
            ans = MAX(ans, max_xor[i]);
            continue;
        }
        max_xor[i] = arr[i] ^ max_xor[jump_over[i]];
        ans = MAX(ans, max_xor[i]);
    }
    printf("%ld\n", ans);
    return 0;
}