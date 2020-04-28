#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = createQueue();
    if (isEmptyQueue(queue))
    {
        printf("Queue is empty\n");
    }
    pushFrontToQueue(5, queue);
    if (!isEmptyQueue(queue))
    {
        printf("Queue is not empty\n");
    }
    pushBackToQueue(9, queue);
    pushFrontToQueue(1, queue);
    pushBackToQueue(7, queue);
    pushBackToQueue(13, queue);
    printf("Current size: %d\n", size(queue));
    printf("%d ", popBackFromQueue(queue));
    printf("%d ", popFrontFromQueue(queue));
    printf("%d ", popBackFromQueue(queue));
    printf("%d ", popFrontFromQueue(queue));
    printf("%d \n", popBackFromQueue(queue));
    printf("Current size: %d\n", size(queue));
    deleteQueue(queue);
    return 0;
}
