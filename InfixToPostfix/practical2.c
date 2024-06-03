#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    return postfix;
}

int evalPostfix()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    allocateMemory(stack, 10);
    char *postfix = (char *)malloc(sizeof(char) * 10);
    printf("enter a postfix sequence : ");
    scanf("%s", postfix);
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
int main()
{
    struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
    int n;

    printf("enter the size of the stack: ");
    scanf("%d", &n);
    allocateMemory(stack, n);
    int x = 1, y;
    while (x)
    {
        printf("enter 0 for exit else\nenter 1 for push || 2 for pop || 3 for postfix conversion || 4 for postfix evaluation || 5 for display the stack: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
            printf("enter a number to push : ");
            scanf("%d", &y);
            push(stack, y);
            break;
        }
        case 2:
        {
            printf("%d element you poped out\n", pop(stack));
            break;
        }
        case 3:
        {
            char *infix = (char * )malloc(sizeof(char)*10);
            printf("enter a infix sequence : ");
            scanf("%s",infix);
            printf("the postfix sequence is : %s\n", infixToPostfix(infix));
            break;
        }
        case 4 :
        {
            printf("the postfix evaluation is : %d\n", evalPostfix());
            break;
        }
        case 5 :
        {
            display(stack);
            break;
        }
        default:
            printf("an invalid input\n");
        }
    }
    printf("this is the modified stack ->\n");
    display(stack);
    return 0;
}