#include "infixtopostfixconverter.h"
int evalPostfix()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    allocateMemory(stack, 10);
    char *postfix = (char *)malloc(sizeof(char) * 10);
    printf("enter a postfix sequence : ");
    gets(postfix);
    int i = 0, num1, num2, ans;
    char element;
    while (i <= strlen(postfix) - 1)
    {
        element = postfix[i];
        if (isdigit(element))
        {
            push(stack, element - 48);
        }
        else
        {
            num1 = pop(stack);
            num2 = pop(stack);
            switch (element)
            {
            case '^':
              ans = 1;
              for (int i = 0; i < num1; i++)
              {
                ans *= num2;
              }
              break;
            case '/':
                ans = num2 / num1;
                break;
            case '+':
                ans = num1 + num2;
                break;
            case '*':
                ans = num1 * num2;
                break;
            case '-':
                ans = num2 - num1;
                break;
            case '%':
                ans = num2 % num1;
                break;
            }
            push(stack, ans);
        }

        i++;
    }
   return pop(stack);
}