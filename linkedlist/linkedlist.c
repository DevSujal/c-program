#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addLast(struct node *head, int data)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
struct node *addhead(struct node *head, int element)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;
    temp->next = head;
    return temp;
}
struct node *add(struct node *head, int element, int position)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = element;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }
    // if (position == 1 || head->next == NULL)
    // {
    //     addhead(&head, element);
    //     return;
    // }
    int i = 1;
    struct node *prev = head;
    struct node *second = head->next;
    while (prev != NULL)
    {
        if (i == position - 1)
        {
            temp->next = second;
            prev->next = temp;
            return head;
        }
        i++;
        prev = prev->next;
        second = second->next;
    }
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return;
    }
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void findMiddle(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list empty\n");
        return;
    }
    struct node *curr1 = head;
    struct node *curr2 = head;
    while (curr2->next != NULL && curr2->next->next != NULL)
    {
        curr1 = curr1->next;
        curr2 = curr2->next->next;
    }
    printf("%d\n", curr1->data);
}

struct node *reverse(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *newnode = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnode;
}

struct node *deletehead(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return head;
    }
    return head->next;
}
struct node *deleteLast(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    struct node *curr = head;
    struct node *prev;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    struct node *temp = curr;
    int num = curr->data;
    prev->next = NULL;
    free(temp);
    return head;
}

struct node *delete(struct node *head, int post)
{
    if (head == NULL)
    {
        printf("Linked List Empty\n");
        return head;
    }

    if (head->next == NULL)
    {
        return head->next;
    }

    struct node *curr = head->next;
    struct node *prev = head;
    while (post > 2)
    {
        if ((curr == NULL))
        {
            printf("index out of bound\n");
            return NULL;
        }
        prev = curr;
        curr = curr->next;
        post--;
    }
    struct node *temp = curr;
    int num = temp->data;
    prev->next = curr->next;
    free(temp);
    return head;
}

void update(struct node *head, int position, int element)
{
    if (head == NULL)
    {
        printf("linked list is empty!\n");
        return;
    }
    struct node *curr = head;
    while (position > 1)
    {
        if (curr == NULL)
        {
            printf("index out of bound!\n");
            return;
        }
        position--;
        curr = curr->next;
    }
    curr->data = element;
}
struct node *deallocateMemory(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    deallocateMemory(head->next);
    free(head);
    return NULL;
}
int search(struct node *head, int element)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
        return -1;
    }

    struct node *curr = head;
    int count = 1;
    while (curr != NULL)
    {
        if (element == curr->data)
        {
            return count;
        }
        curr = curr->next;
        count++;
    }
    return -1;
}
void fun2(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next != NULL)
    {
        fun2(head->next);
    }
    printf("%d ", head->data);
}
// struct node *create(int size)
// {
//     if (size == 0)
//     {
//         return NULL;
//     }
//     struct node * temp  = NULL;
//     struct node *head = NULL;
//     while (size > 0)
//     {

//         struct node *newNode = (struct node *)malloc(sizeof(struct node));
//         int num;
//         printf("enter the data of node :");
//         scanf("%d", &num);
//         newNode->data = num;
//         newNode->next = NULL;
//         if (temp == NULL)
//         {
//             head = temp = newNode;
//         }
//         else
//         {
//             head->next = newNode;
//             head = newNode;
//         }
//         size--;
//     }
//         return temp;
// }
struct node *create(struct node *head, int size)
{
    if (size == 0)
    {
        return NULL;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("enter the data of node :");
    scanf("%d", &num);
    newNode->data = num;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
        head = newNode;
    }
    create(head, size - 1);
    return head;
}
void removeDuplicates(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            struct node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            continue;
        }
        curr = curr->next;
    }
}

struct node *mergeTwoLinkedList(struct node *head1, struct node *head2)
{

    struct node *newnode = NULL, *curr1 = head1, *curr2 = head2, *ptr = NULL;

    while (curr1 != NULL && curr2 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        if (curr1->data <= curr2->data)
        {
            temp->data = curr1->data;
            curr1 = curr1->next;
        }
        else
        {
            temp->data = curr2->data;
            curr2 = curr2->next;
        }
        if (newnode == NULL)
        {
            newnode = ptr = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = temp;
        }
    }
    while (curr1 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        temp -> data  = curr1 -> data;
        ptr -> next = temp;
        ptr = temp;
        curr1 = curr1 -> next;
    }
    while (curr2 != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        temp -> data  = curr2 -> data;
        ptr -> next = temp;
        ptr = temp;
        curr2 = curr2 -> next;
    }
    return newnode;
}
/*
void main()
{

    struct node *head = NULL;
    int choice;
    do
    {
        printf("\nenter 0 for exit else \nenter 1 for add || 2 for delete || 3 for Middle || 4 for update || 5 for reverse \n6 for display || 7 for search || 8 for create || 9 for remove duplicates || 10 clear linked list : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int x;
            printf("enter 1 for addhead || 2 for addLast || 3 for add in between : ");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
            {
                int num;
                printf("enter element to add head : ");
                scanf("%d", &num);
                head = addhead(head, num);
                break;
            }
            case 2:
            {
                int num;
                printf("enter element to add in last : ");
                scanf("%d", &num);
                head = addLast(head, num);
                break;
            }
            case 3:
            {
                int post, num;
                printf("enter element to add in between : ");
                scanf("%d", &num);
                printf("enter a position to add : ");
                scanf("%d", &post);
                head = add(head, num, post);
                break;
            }
            }
            break;
        }
        case 2:
        {
            int x;
            printf("enter 1 for deletehead || 2 for deleteLast || 3 for delete in between : ");
            scanf("%d", &x);

            switch (x)
            {
            case 1:
            {
                head = deletehead(head);
                break;
            }
            case 2:
            {
                head = deleteLast(head);
                break;
            }
            case 3:
            {
                int post;
                printf("enter a position to delete : ");
                scanf("%d", &post);
                head = delete (head, post);
                break;
            }
            }
            break;
        }
        case 3:
        {
            findMiddle(head);
            break;
        }
        case 4:
        {
            int post, x;
            printf("enter a position to update : ");
            scanf("%d", &post);
            printf("enter element to add : ");
            scanf("%d", &x);
            update(head, post, x);
            break;
        }
        case 5:
        {
            head = reverse(head);
            break;
        }
        case 6:
        {
            display(head);
            break;
        }
        case 7:
        {
            int x;
            printf("enter element to search : ");
            scanf("%d", &x);
            printf("%d is present in position %d", x, search(head, x));
            break;
        }
        case 8:
        {
            int size;
            printf("enter the size of the linked list : ");
            scanf("%d", &size);
            head = create(NULL, size);
            break;
        }
        case 9:
        {
            removeDuplicates(head);
            break;
        }
        case 10:
        {
            head = deallocateMemory(head);
            break;
        }
        case 0:
        {
            head = deallocateMemory(head);
            break;
        }
        default:
            printf("an invalid input\n");
        }
    } while (choice != 0);
}
*/
void main()
{
    struct node *head1 = create(NULL, 5);
    struct node *head2 = create(NULL, 4);

   struct node* head3 =  mergeTwoLinkedList(head1, head2);
    
    display(head3);
}