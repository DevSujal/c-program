// priority Queue Using Linked List ->

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char *process;
    int burst;
    int priority;
    struct node *next;
};
struct node *insert(struct node *head, char *process, int burst, int priority)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->process = process;
    newNode->burst = burst;
    newNode->priority = priority;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    if (newNode->priority < head->priority)
    {
        newNode->next = head;
        return newNode;
    }
    if (head -> next == NULL)
    {
        head -> next = newNode;
        return head;
    }
    
    struct node *ptr = head;
    while (newNode -> priority >= ptr -> next -> priority)
    {
        ptr = ptr->next;
        if(ptr -> next == NULL){
            break;
        }
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

struct node * delete(struct node * first){
    if (first == NULL)
    {
       printf("linked list is empty\n");
       return NULL;
    }
    
    struct node* temp=first;
    first = first -> next;
    free(temp);
    return first;
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("process = %s burst = %d and priority = %d\n", ptr->process, ptr->burst, ptr->priority);
        ptr = ptr->next;
    }
}
void main()
{
    struct node *head = NULL;
    head = insert(head, "p1", 9, 3);
    head = insert(head, "p2", 8, 5);
    head = insert(head, "p3", 9, 4);
    head = insert(head, "p4", 9, 3);
    head = insert(head, "p5", 9, 1);
    head = insert(head, "p5", 9, 2);
    head = delete(head);
    display(head);
}