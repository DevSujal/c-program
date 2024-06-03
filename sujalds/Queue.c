#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"


int main()
{
    struct Queue *queue;
    allocateMemory(queue, 10);

    insert(queue, 1, 11);
    insert(queue, 1, 12);
    insert(queue, 1, 12);
    insert(queue, 1, 14);
    insert(queue, 2, 15);
    insert(queue, 2, 16);
    insert(queue, 2, 17);
    insert(queue, 2, 18);
    insert(queue, 2, 19);
    insert(queue, 2, 19);
    insert(queue, 2, 19);
    insert(queue, 1, 13);

    // insert(queue, 2, 19);

    // printf("%d\n", queue->front[0]);
    // printf("%d\n", queue->front[1]);
    // printf("%d\n", queue->rear[0]);
    // printf("%d\n", queue->rear[1]);

    // delete (queue, 1);
    // delete (queue, 2);

    // printf("%d\n", queue->front[0]);
    // printf("%d\n", queue->front[1]);
    // printf("%d\n", queue->rear[0]);
    // printf("%d\n", queue->rear[1]);

    printf("%d\n", queue -> rear[0]);
    printf("%d\n", queue -> rear[1]);
    printQueue(queue);
    insert(queue, 2, 99);
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));
    // printf("%d\n", delete(queue, 2));

    printf("%d\n", delete(queue, 1));
    printf("%d\n", delete(queue, 1));
    printf("%d\n", delete(queue, 1));
    printf("%d\n", delete(queue, 1));
    printf("%d\n", delete(queue, 1));
    return 0;
}