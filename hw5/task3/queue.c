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
    if (newQueue == NULL)
    {
        exit(1);
    }
    newQueue->first = NULL;
    newQueue->end = NULL;
    newQueue->length = 0;
    return newQueue;
}

QueueElement* createQueueElement(Queue* queue, char value)
{
	if (queue == NULL)
    {
        exit(1);
    }
    QueueElement *newQueueElement = (QueueElement*) malloc(sizeof(QueueElement));
    if (newQueueElement == NULL)
    {
        exit(1);
    }
    newQueueElement->value = value;
    newQueueElement->next = NULL;
    return newQueueElement;
}

void pushToQueue(char value, Queue *queue)
{
	if (queue == NULL)
    {
        exit(1);
    }
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

bool isEmptyQueue(Queue *queue)
{
	if (queue == NULL)
    {
        exit(1);
    }
    if (queue->length == 0)
    {
        return true;
    }
    return false;
}

char popFromQueue(Queue* queue)
{
	if (queue == NULL)
    {
        exit(1);
    }
    if (isEmptyQueue(queue))
    {
        return 0;
    }
    if (queue->length == 1)
    {
        queue->end = NULL;
    }
    QueueElement *poppedElement = queue->first;
    char value = poppedElement->value;
    queue->first = poppedElement->next;
    free(poppedElement);
    --queue->length;
    return value;
}

void deleteQueue(Queue *queue)
{
    while (queue->first != NULL)
    {
        QueueElement *currentElement = queue->first;
        queue->first = currentElement->next;
        free(currentElement);
    }
    free(queue);
}

