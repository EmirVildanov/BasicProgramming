#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct QueueElement
{
    int value;
    int priority;
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

QueueElement* createQueueElement(Queue* queue, int value, int priority)
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
    newQueueElement->priority = priority;
    return newQueueElement;
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

void insertNewElement(Queue *queue, QueueElement *currentElement, int value, int priority)
{
    int rememberValue = currentElement->value;
    int rememberPriority = currentElement->priority;
    QueueElement *newElement = createQueueElement(queue, rememberValue, rememberPriority);
    if (currentElement == queue->end)
    {
        queue->end = newElement;
    }
    newElement->next = currentElement->next;
    currentElement->next = newElement;
    currentElement->value = value;
    currentElement->priority = priority;
    ++queue->length;
}

void enqueue(Queue *queue, int value, int priority)
{
    if (queue == NULL)
    {
        return;
    }
    QueueElement *newElement = createQueueElement(queue, value, priority);
    if (isEmptyQueue(queue))
    {
        queue->first = newElement;
        queue->end = newElement;
        ++queue->length;
        return;
    }
    QueueElement *currentElement = queue->first;
    for (int i = 0; i < queue->length; ++i)
    {
        if (currentElement->priority <= priority)
        {
            insertNewElement(queue, currentElement, value, priority);
            return;
        }
        if (i != queue->length - 1)
        {
            currentElement = currentElement->next;
        }
    }
    currentElement->next = newElement;
    queue->end = currentElement;
    ++queue->length;
}

int dequeue(Queue *queue)
{
    if (queue == NULL || isEmptyQueue(queue))
    {
        return -1;
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

