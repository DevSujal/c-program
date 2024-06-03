#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A real time messaging app using queue

struct node
{
    char *phone;
    char *desc;
};

struct Message
{
    struct node *messageArray;
    int front;
    int rear;
    int size;
};

struct Message *createMessagingApp(int size)
{
    struct Message *App = (struct Message *)malloc(sizeof(struct Message));
    App->messageArray = (struct node *)malloc(sizeof(struct node) * size);
    App->front = -1;
    App->rear = -1;
    App->size = size;
    return App;
}
struct Message *sizeIncreament(struct Message *App);

struct node createnode(char *phone, char *desc)
{
    struct node newnode;
    newnode.phone = phone;
    newnode.desc = desc;
    return newnode;
}

struct Message *add(struct Message *App, char *phone, char *desc)
{
    if (App->rear == -1)
    {
        App->front = App->rear = 0;
        App->messageArray[App->rear] = createnode(phone, desc);
        return App;
    }
    if (App->front == (App->rear + 1) % App->size)
    {
        App = sizeIncreament(App);
        add(App, phone, desc);
        return App;
    }
    App->rear = (App->rear + 1) % App->size;
    App->messageArray[App->rear] = createnode(phone, desc);
    return App;
}

struct node minus(struct Message *App)
{
    if (App->rear == -1)
    {
        printf("The messaging app is empty.\n");
        struct node placeholder;
        placeholder.phone = "Unknown";
        placeholder.desc = "kya dekh raha hai kuch bhi to nahi hai\n";
        return placeholder;
    }
    if (App->rear == App->front)
    {
        struct node value = App->messageArray[App->front];
        App->front = App->rear = -1;
        return value;
    }
    struct node value = App->messageArray[App->front];
    App->front = (App->front + 1) % App->size;
    return value;
}
struct Message *sizeIncreament(struct Message *App)
{
    int size = App->size;
    struct Message *newApp = createMessagingApp(size + size / 2);
    int i = 0;
    while (App->front != App->rear)
    {
        struct node value = minus(App);
        add(newApp, value.phone, value.desc);
    }
    struct node value = minus(App);
    add(newApp, value.phone, value.desc);
    free(App);
    return newApp;
}
void display(struct Message *App)
{
    if(App -> rear == -1){
        printf("Messaging App is emty\n");
        return;
    }
    for (int i = App->front; i != App->rear; i = (i + 1) % App->size)
    {
        struct node value = App->messageArray[i];
        printf("Phone number = %s\n Message = %s\n", value.phone, value.desc);
    }
    struct node value = App->messageArray[App->rear];
    printf("Phone number = %s\n Message = %s\n", value.phone, value.desc);
}

void displayN(struct Message *App, int n)
{
    if (n > App->rear + 1 || n <= 0 || App -> rear == -1){
        printf("Invalid input! Please enter a valid number of messages to be displayed.\n");
        return;
    }
    int i = App->front;
    while (n > 0)
    {
        struct node value = App->messageArray[i];
        printf("Phone number = %s\n Message = %s\n", value.phone, value.desc);
        if (i == App->rear)
        {
            break;
        }
        i = (i + 1) % App -> size;
        n--;
    }
}
