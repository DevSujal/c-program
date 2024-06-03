#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '(':
        return 0;
    }
}
void infixToPostfix(char * infix)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    allocateMemory(stack, 50);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1)), x;
    int i = 0, j = 0;
    while (infix[j] != '\0')
    {
        if (isalnum(infix[j]))
        {
           postfix[i] = infix[j];
           printf("%c\n",postfix[i]);
        }
        else if (infix[j] == '(')
        {
            push(stack, infix[j]);
        }
        else if (infix[j] == ')')
        {
            while ((x = pop(stack)) != '(')
            {
                postfix[i] = x;
                printf("%c\n",postfix[i]);
                i++;
            }
            i--;
        }
        else
        {
            while (prec(peek(stack)) >= prec(infix[j]))
            {
                postfix[i] = pop(stack);
                printf("%c\n",postfix[i]);
                i++;
            }
                i--;
                push(stack, infix[j]);
        }
       j++;
       i++;
    }
    while (!isEmpty(stack))
    {
        postfix[i] = pop(stack);
        printf("%c\n",postfix[i]);
        i++;
    }
    postfix[i] = '\0';
    printf("%s", postfix);

}
void main()
{
    infixToPostfix("a+(b-c)");
}