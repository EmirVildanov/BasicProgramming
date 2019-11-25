#pragma once

#include <stdbool.h>

struct Queue;
struct QueueElement;

typedef struct QueueElement QueueElement;
typedef struct Queue Queue;

Queue* createQueue();
QueueElement* createQueueElement(Queue* queue, char value);
bool isEmptyQueue(Queue *queue);
void pushToQueue(char value, Queue *queue);
char popFromQueue(Queue* queue);
void deleteQueue(Queue *queue);

