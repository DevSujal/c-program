#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int age;
    struct Node *nextnode;
};

void allocatamemory(struct Node *newnode)
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
}
void initializenod(struct Node *newnode, int age)
{
    newnode->age = age;
    newnode->nextnode = NULL;
}
struct Node* addfirst(struct Node *headnode, int element)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    initializenod(newnode, element);
    if (headnode == NULL)
    {
        headnode = newnode;
        printf("naak");
    }
    newnode->nextnode = headnode;
    headnode = newnode;
    // printf("%d\n", headnode -> age);
    return headnode;
}

void printlist(struct Node *headnode)
{
    if(headnode == NULL){
        printf("list is empty!");
    }
    struct Node *currnode = headnode;

    while (currnode != NULL)
    {
        printf("%d -> ", currnode->age);
        currnode = currnode->nextnode;
    }
    printf("null");
}

int main()
{
    
}