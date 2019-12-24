#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *queue = createQueue();
    enqueue(queue, 3, 5);
    enqueue(queue, 7, 8);
    enqueue(queue, 9, 2);
    int poppedElement = dequeue(queue);
    printf("Popped element is %d\n", poppedElement);
    poppedElement = dequeue(queue);
    printf("Popped element is %d\n", poppedElement);
    poppedElement = dequeue(queue);
    printf("Popped element is %d\n", poppedElement);
    deleteQueue(queue);
    return 0;
}