// this is the implementation of 2 Quese using one array
// first -> from left to right
// second -> from right to left

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue
{
    int *arr;
    int *front;
    int *rear;
    int size;
};

void allocateMemory(struct Queue *queue, int size)
{
    queue->arr = (int *)malloc(sizeof(int) * size);
    queue->size = size;
    queue->front = (int *)malloc(sizeof(int) * 2);
    queue->rear = (int *)malloc(sizeof(int) * 2);
    queue->front[0] = -1;
    queue->rear[0] = -1;
    queue->front[1] = size;
    queue->rear[1] = size;
}

void insert(struct Queue *queue, int wqueue, int element)
{
    int idx = wqueue - 1;
    if (idx == 0)
    {
        if (queue->rear[idx] == -1)
        {
            queue->front[idx] = 0;
            queue->rear[idx] = 0;
            queue->arr[queue->rear[idx]] = element;
            return;
        }
        if (queue->rear[1] == queue->rear[idx] + 1)
        {
            puts("Queue is full");
            return;
        }
        queue->rear[idx]++;
        queue->arr[queue->rear[idx]] = element;
        return;
    }

    if (queue->rear[idx] == queue->size)
    {
        queue->front[idx]--;
        queue->rear[idx]--;
        queue->arr[queue->rear[idx]] = element;
        return;
    }
    if (queue->rear[0] == queue->rear[idx] - 1)
    {
        puts("Queue is full");
        return;
    }
    queue->rear[idx]--;
    queue->arr[queue->rear[idx]] = element;
}

int delete(struct Queue *queue, int wqueue)
{
    int idx = wqueue - 1;

    if (idx == 0)
    {
        if (queue->rear[idx] == -1)
        {
            puts("Queue is empty");
            return -1;
        }
        if (queue->rear[idx] == queue->front[idx])
        {
            int num = queue->arr[queue->front[idx]];
            queue->front[idx] = -1;
            queue->rear[idx] = -1;
            return num;
        }
        int num = queue->arr[queue->front[idx]];
        queue->front[idx]++;
        return num;
    }

    if (queue->rear[idx] == queue->size)
    {
        puts("Queue is empty");
        return -1;
    }
    if (queue->rear[idx] == queue->front[idx])
    {
        int num = queue->arr[queue->front[idx]];
        queue->front[idx] = queue->size;
        queue->rear[idx] = queue->size;
        return num;
    }
    int num = queue->arr[queue->front[idx]];
    queue->front[idx]--;
    return num;
}

void printQueue(struct Queue *queue)
{
    puts("first Queue ie left to right");
    int idx = queue->front[0];

    while (idx != queue->rear[0] + 1)
    {
        printf("%d ", queue->arr[idx]);
        idx++;
    }
    puts("\nsecond Queue ie right to left");
    idx = queue->front[1];
    while (idx != queue->rear[1] - 1)
    {
        printf("%d ", queue->arr[idx]);
        idx--;
    }
    printf("\n");
}