#pragma once

#include <stdbool.h>

struct Queue;
struct QueueElement;

typedef struct QueueElement QueueElement;
typedef struct Queue Queue;

Queue* createQueue();
QueueElement* createQueueElement(Queue* queue, int value);
bool isEmptyQueue(Queue *queue);
void pushFrontToQueue(int value, Queue *queue);
void pushBackToQueue(int value, Queue *queue);
char popFrontFromQueue(Queue* queue);
char popBackFromQueue(Queue* queue);
int size(Queue *queue);
void deleteQueue(Queue *queue);

