#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

void init(struct Stack *stack, char ptr[], int idx)
{
    if (idx < 0)
    {
        return;
    }
    push(stack, ptr[idx]);
    init(stack, ptr, idx - 1);
}
int preceoder(char element)
{
    switch (element)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    default:
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    allocateMemory(stack, 50);

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (preceoder(infix[i]) > preceoder(peek(stack)))
            {
                push(stack, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(stack);
                j++;
            }
        }
    }
    while (!isEmpty(stack))
    {
        postfix[j] = pop(stack);
        j++;
    }
    postfix[j] = '\0';
    free(stack);
    return postfix;
}
// void main()
// {
//     struct Stack *stack;

//     char *infix = "a-b+t/6";

//     puts(infixToPostfix(infix));
// }