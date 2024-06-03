#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;
    int size;
    int finalSize;
};

void allocateMemory(struct Stack *arr, int finalSize)
{
    arr->arr = (int *)malloc(sizeof(int) * finalSize);
    arr->size = 0;
    arr->finalSize = finalSize;
}

int isEmpty(struct Stack *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *stack, int element)
{

    if (stack->size >= stack->finalSize)
    {
        printf("insertion is not possible");
        return;
    }
    stack->arr[stack->size] = element;
    stack->size++;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        // printf("stack is empty");
        return -1;
    }

    int num = stack->arr[stack->size - 1];
    stack->arr[stack->size - 1] = '\0';
    stack->size--;
    return num;
}
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        // printf("stack is empty");
        return -1;
    }

    return stack->arr[stack->size - 1];
}

void removeNthElement(struct Stack *stack, int position)
{
    if (position == 1)
    {
        pop(stack);
        return;
    }
    int top = pop(stack);
    removeNthElement(stack, position - 1);
    push(stack, top);
}
void pushAtAnyPostion(struct Stack *stack, int position, int element)
{
    if (position == 1)
    {
        push(stack, element);
        return;
    }
    int top = pop(stack);
    pushAtAnyPostion(stack, position - 1, element);
    push(stack, top);
}

void pushAtTheBottom(struct Stack *stack, int element)
{
    if (isEmpty(stack))
    {
        push(stack, element);
        return;
    }

    int top = pop(stack);
    pushAtTheBottom(stack, element);

    push(stack, top);
}