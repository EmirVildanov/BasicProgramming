#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct QueueElement
{
    char value;
    QueueElement* next;
    QueueElement* previous;
};

struct Queue
{
    QueueElement* first;
    QueueElement* end;
    int size;
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
    newQueue->size = 0;
    return newQueue;
}

QueueElement* createQueueElement(Queue* queue, int value)
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
    newQueueElement->previous = NULL;
    return newQueueElement;
}

void pushFrontToQueue(int value, Queue *queue)
{
	if (queue == NULL)
    {
        return;
    }
    QueueElement *newElement = createQueueElement(queue, value);
    if (isEmptyQueue(queue))
    {
        queue->first = newElement;
        queue->end = newElement;
    }
    else
    {
        QueueElement *currentFirst = queue->first;
        queue->first = newElement;
        newElement->next = currentFirst;
        currentFirst->previous = newElement;
    }
    ++queue->size;
}

void pushBackToQueue(int value, Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    QueueElement *newElement = createQueueElement(queue, value);
    if (isEmptyQueue(queue))
    {
        queue->first = newElement;
        queue->end = newElement;
    }
    else
    {
        QueueElement *currentEnd = queue->end;
        queue->end = newElement;
        newElement->previous = currentEnd;
        currentEnd->next = newElement;
    }
    ++queue->size;
}

bool isEmptyQueue(Queue *queue)
{
	if (queue == NULL)
    {
        return true;
    }
    if (queue->size == 0)
    {
        return true;
    }
    return false;
}

char popFrontFromQueue(Queue* queue)
{
	if (queue == NULL)
    {
        return '\0';
    }
    if (isEmptyQueue(queue))
    {
        return '\0';
    }
    QueueElement *poppedElement = queue->first;
    int value = poppedElement->value;
    queue->first = poppedElement->next;
    free(poppedElement);
    if (queue->size == 1)
    {
        queue->end = NULL;
        queue->first = NULL;
    }
    --queue->size;
    return value;
}

char popBackFromQueue(Queue* queue)
{
    if (queue == NULL)
    {
        return '\0';
    }
    if (isEmptyQueue(queue))
    {
        return '\0';
    }
    QueueElement *poppedElement = queue->end;
    int value = poppedElement->value;
    queue->end = poppedElement->previous;
    free(poppedElement);
    if (queue->size == 1)
    {
        queue->end = NULL;
        queue->first = NULL;
    }
    --queue->size;
    return value;
}

int size(Queue *queue)
{
	if (queue == NULL)
    {
        return -1;
    }
    return queue->size;
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