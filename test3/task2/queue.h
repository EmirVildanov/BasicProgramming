#pragma once

#include <stdbool.h>

struct Queue;
struct QueueElement;

typedef struct QueueElement QueueElement;
typedef struct Queue Queue;

Queue* createQueue();
QueueElement* createQueueElement(Queue* queue, int value, int priority);
bool isEmptyQueue(Queue *queue);

void enqueue(Queue *queue, int value, int priority);
int dequeue(Queue *queue);

void deleteQueue(Queue *queue);

