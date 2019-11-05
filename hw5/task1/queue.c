#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct QueueElement
{
    char value;
    QueueElement* next;
};

struct Queue
{
    QueueElement* first;
    QueueElement* end;
    int length;
};

Queue* createQueue()
{
    Queue *newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue ->first = NULL;
    newQueue ->end = NULL;
    newQueue ->length = 0;
    return newQueue;
}

QueueElement* createQueueElement(Queue* queue, int value)
{
    QueueElement *newQueueElement = (QueueElement*) malloc(sizeof(QueueElement));
    newQueueElement ->value = value;
    newQueueElement ->next = NULL;
    return newQueueElement;
}

void pushToQueue(int value, Queue *queue)
{
    QueueElement *newElement = createQueueElement(queue, value);
    if (isEmptyQueue(queue))
    {
        queue->first = newElement;
    }
    else
    {
        queue->end->next = newElement;
    }
    queue->end = newElement;
    ++queue->length;
}

bool addToQueue()
{
    QueueElement *newPerson = (QueueElement*) malloc(sizeof(QueueElement));
}

void front(Queue* queue)
{

}

bool isEmptyQueue(Queue *queue)
{
    if (queue->length == 0)
    {
        return true;
    }
    return false;
}

char popFromQueue(Queue* queue)
{
    if (isEmptyQueue(queue))
    {
        return 0;
    }
    if (queue->length == 1)
    {
        queue->end = NULL;
    }
    QueueElement *poppedElement = queue->first;
    int value = poppedElement->value;
    queue->first = poppedElement->next;
    free(poppedElement);
    --queue->length;
    return value;
}

int size(Queue *queue)
{
    return queue->length;
}

void deleteQueue(Queue *queue)
{
    while (queue->first != NULL)
    {
        QueueElement *currentElement = queue->first;
        queue->first = currentElement->next;
        free(currentElement);
    }
}
