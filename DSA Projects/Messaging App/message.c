#include <stdio.h>
#include "CircularQueue.h"
void main()
{
    struct Message *App = createMessagingApp(5);
    int choice = 0;
    do
    {
        printf("enter the choice 1 message insertion 2 message deletion\n3 message display 4 display n number of messages : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char *phone = (char *)malloc(sizeof(char) * 10), *desc = (char *)malloc(sizeof(char) * 100);
            printf("enter a number to message : ");
            scanf("%s", phone);

            printf("write a message : ");
            scanf("%s", desc);

            App = add(App, phone, desc);
            break;
        }

        case 2:
        {
            struct node value = minus(App);
            printf("Phone number = %s\n Message = %s\n", value.phone, value.desc);
            break;
        }

        case 3:
        {
            display(App);
            break;
        }
        case 4:
        {
            int n;
            printf("enter how many messages you want to see : ");
            scanf("%d", &n);
            displayN(App, n);
        }

        default:
            break;
        }
    } while (choice != 0);
}
