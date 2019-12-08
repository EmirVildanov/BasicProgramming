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
        return NULL;
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
        return NULL;
    }
    QueueElement *newQueueElement = (QueueElement*) malloc(sizeof(QueueElement));
    if (newQueueElement == NULL)
    {
        return NULL;
    }
    newQueueElement->value = value;
    newQueueElement->next = NULL;
    return newQueueElement;
}

void pushToQueue(char value, Queue *queue)
{
	if (queue == NULL)
    {
        return ;
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
        return true;
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
        return '\0';
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
    if (queue == NULL)
    {
        return;
    }
    while (queue->first != NULL)
    {
        QueueElement *currentElement = queue->first;
        queue->first = currentElement->next;
        free(currentElement);
    }
    free(queue);
}

