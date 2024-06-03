#include <stdio.h>
#include "DoublyLinkedList.h"
void main()
{
    int choice;
    struct node *first = NULL;
    do
    {
        printf("Enter 0 for exit\n1 for create\n2 for add\n3 for display\n4 for display in Reverse\n5 sort\n6 for remove\n7 for Search\n8 for update\n9 for call\n10 for removeDuplicates : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int num;
            printf("enter how many numbers you want to add : ");
            scanf("%d", &num);
            first = create(num);
            break;
        case 2:
            first = add(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            displayReverse(first);
            break;
        case 5:
            printf("enter 1 for asscending sort according to name\n2 for descending sort according to name\n3 asscending sort according to number\n4 for descending sort according to number : ");
            scanf("%d", &choice);
            first = sort(first, choice);
            break;
        case 6:
            char *data = (char *)malloc(sizeof(char) * 20);
            printf("enter the name or the number you want to remove : ");
            gets(data);
            first = delete (first, data);
            break;
        case 7:
            char *data = (char *)malloc(sizeof(char) * 20);
            printf("enter the name or the number you want to search : ");
            gets(data);
            struct node *temp = search(first, data);
            printf("Name = %s\nNumber = %s", temp->name, temp->number);
            break;
        case 8:
            char *data = (char *)malloc(sizeof(char) * 20);
            printf("enter the name or the number you want to update : ");
            gets(data);
            char *name = (char *)malloc(sizeof(char) * 20);
            char *number = (char *)malloc(sizeof(char) * 20);
            printf("enter new name :");
            gets(name);
            printf("enter new mobile number : ");
            gets(number);
            update(first, data, name, number);
            break;
        case 9:
            char *data = (char *)malloc(sizeof(char) * 20);
            printf("enter the name or the number you want to call : ");
            gets(data);
            call(first, data);
            break;
        case 10:
            removeDuplicates(first);
            break;

        case 0:
            clear(first);
            first = NULL;
            break;
        default:
            printf("an invalid choice");
            break;
        }
    } while (choice);
}