#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *name, *number;
    struct node *next;
};

void display(struct node *first)
{
    if (first == NULL)
    {
        return;
    }

    printf("\nName :- %s", first->name);
    printf("\nNumber :- %s\n", first->number);

    display(first->next);
}
void displayReverse(struct node *first)
{

    if (first == NULL)
    {
        return;
    }
    displayReverse(first->next);

    printf("\nName :- %s", first->name);
    printf("\nNumber :- %s\n", first->number);
}

struct node *nameAscendSort(struct node *head, char *name, char *number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (strcmp(newNode->name, head->name) < 0)
    {
        newNode->next = head;
        return newNode;
    }
    if (head->next == NULL)
    {
        head->next = newNode;
        return head;
    }

    struct node *ptr = head;
    while (strcmp(newNode->name, ptr->next->name) >= 0)
    {
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}
struct node *nameDescendSort(struct node *head, char *name, char *number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (strcmp(newNode->name, head->name) > 0)
    {
        newNode->next = head;
        return newNode;
    }
    if (head->next == NULL)
    {
        head->next = newNode;
        return head;
    }

    struct node *ptr = head;
    while (strcmp(newNode->name, ptr->next->name) <= 0)
    {
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}
struct node *numberAscendSort(struct node *head, char *name, char *number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (strcmp(newNode->number, head->number) < 0)
    {
        newNode->next = head;
        return newNode;
    }
    if (head->next == NULL)
    {
        head->next = newNode;
        return head;
    }

    struct node *ptr = head;
    while (strcmp(newNode->number, ptr->next->number) >= 0)
    {
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}
struct node *numberDescendSort(struct node *head, char *name, char *number)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (strcmp(newNode->number, head->number) > 0)
    {
        newNode->next = head;
        return newNode;
    }
    if (head->next == NULL)
    {
        head->next = newNode;
        return head;
    }

    struct node *ptr = head;
    while (strcmp(newNode->number, ptr->next->number) <= 0)
    {
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

struct node *sort(struct node *first, int whichSort)
{
    struct node *newlinkedlist = NULL;
    struct node *ptr = first;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        switch (whichSort)
        {
        case 1:
            newlinkedlist = nameAscendSort(newlinkedlist, ptr->name, ptr->number);
            break;
        case 2:
            newlinkedlist = nameDescendSort(newlinkedlist, ptr->name, ptr->number);
            break;
        case 3:
            newlinkedlist = numberAscendSort(newlinkedlist, ptr->name, ptr->number);
            break;
        case 4:
            newlinkedlist = numberDescendSort(newlinkedlist, ptr->name, ptr->number);
            break;
        }
        ptr = ptr->next;
        free(temp);
    }
    return newlinkedlist;
}

struct node *search(struct node *first, char *data)
{
    if (first == NULL)
    {
        return NULL;
    }
    else if (!(strcmp(first->name, data) && strcmp(first->number, data)))
    {
        return first;
    }
    search(first->next, data);
}
struct node *delete(struct node *first, char *data)
{
    if (first == NULL || !(strcmp(first->name, data) && strcmp(first->number, data)))
    {
        struct node *temp = first->next;
        free(first);
        return temp;
    }
    struct node *ptr = first;
    while (ptr->next != NULL)
    {
        if (!(strcmp(ptr->next->name, data) && strcmp(ptr->next->number, data)))
        {
            struct node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            return first;
        }
        ptr = ptr->next;
    }
}
void update(struct node *first, char *old, char *newname, char *newnumber)
{
    if (first == NULL)
    {
        return;
    }
    if (!(strcmp(first->name, old) && strcmp(first->number, old)))
    {
        first->name = newname;
        first->number = newnumber;
        return;
    }
    update(first->next, old, newname, newnumber);
}
void call(struct node *first, char *data)
{
    struct node *temp = search(first, data);
    printf("\nCalling to %s.....\nNumber = %s", temp->name, temp->number);
}
struct node *add(struct node *first)
{
    char *name = (char *)malloc(sizeof(char) * 20);
    char *number = (char *)malloc(sizeof(char) * 20);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the name of the person : ");
    gets(name);

label:
    printf("enter the mobile number : ");
    gets(number);
    if (strlen(number) != 10)
    {
        printf("Invalid mobile number please enter a valid mobile number \n");
        goto label;
    }
    newnode->name = name;
    newnode->number = number;
    newnode->next = first;
    return newnode;
}

struct node *create(int size)
{
    struct node *first = NULL;
    while (size > 0)
    {
        first = add(first);
        size--;
    }
    return first;
}

void removeDuplicates(struct node *first)
{
    struct node *ptr = sort(first, 3);
    while (ptr->next != NULL)
    {
        if (!strcmp(ptr->number, ptr->next->number))
        {
            struct node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            continue;
        }
        ptr = ptr->next;
    }
}
void clear(struct node *first)
{
    if(first == NULL)
    {
        return;
    }
    clear(first -> next);
    free(first);
}