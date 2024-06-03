#include <stdio.h>
#include <stdlib.h>
struct Queue  {
    int *arr;
    int front, rear, max;
};

int isFull(struct Queue * queue){
    return queue -> front == (queue -> rear + 1) % queue -> max;
}
int isEmpty(struct Queue * queue){
    return queue -> rear == -1;
}
void allocateMemory(struct Queue * queue, int max){
    queue -> arr = (int *)malloc(sizeof(int) * max);
    queue -> front = -1;
    queue -> rear = -1;
    queue -> max = max;
}

void enqueue(struct Queue * queue, int element){
    if(isFull(queue)){
        printf("\nQueue is full\n");
        return;
    }
    if(queue -> rear == -1){
       queue -> front = 0;
       queue -> rear = 0;
       queue -> arr[queue -> rear] = element;
       return;
    }
    queue -> rear = (queue -> rear + 1) % queue -> max;
    queue -> arr[queue -> rear] = element;
}
int dqueue(struct Queue * queue){

    if(isEmpty(queue)){
        printf("queue is Empty \n");
        return -1;
    }
    if(queue -> front == queue -> rear){
    int curr = queue -> arr[queue -> front];
        queue -> front = -1;
        queue -> rear = -1;
        return curr;
    }
    int curr = queue -> arr[queue -> front];
       queue -> front = (queue -> front + 1) % queue -> max;
       return curr;
}
void display (struct Queue * queue){
    int curr = queue -> front;
    
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return;
    }
   
    while(curr != queue -> rear){
        printf("%d ", queue -> arr[curr]);
        curr = (curr + 1) % queue -> max;
    }
     printf("%d \n", queue -> arr[curr]);
}
