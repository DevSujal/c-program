#include <stdio.h>
#include "circular.h"

int main()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    int n;
    printf("enter the queue size : ");
    scanf("%d", &n);
    allocateMemory(queue, n);

    int x = 1;
    while (x != 0)
    {
        printf("enter 0 to exit else \nenter : 1 for add || 2 for delete || 3 for display: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
        {
            int i;
            printf("enter the element to add : ");
            scanf("%d", &i);
            enqueue(queue, i);
            break;
        }
        case 2:
        {
            printf("the element you removed is : %d\n", dqueue(queue));
            break;
        }
        case 3:
        {
            display(queue);
            break;
        }
        default:
            printf("an invalid input\n");
        }
    }
}
