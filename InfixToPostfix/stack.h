#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int *arr;
    int size;
    int final_size;
};
int isEmpty(struct Stack *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }
    return 0;
}
void allocateMemory(struct Stack *stack, int final_size)
{
    stack->arr = (int *)malloc(sizeof(int) * final_size);
    stack->final_size = final_size;
    stack->size = 0;
}
void push(struct Stack *stack, int element)
{
    if (stack->size == stack->final_size)
    {
        printf("stack is full\n");
        return;
    }
    stack->arr[stack->size] = element;
    stack->size++;
}
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->arr[(stack->size) - 1];
}
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    stack->size--;
    return stack->arr[stack->size];
}
void display(struct Stack *stack)
{
    int top = pop(stack);
    if (top == -1)
    {
        return;
    }
    printf("%d\n", top);
    display(stack);
    push(stack, top);
}
