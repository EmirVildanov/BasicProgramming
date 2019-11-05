#ifndef FIFO_QUEUE_H
#define FIFO_QUEUE_H

#include <stdbool.h>

struct Queue;
struct QueueElement;

typedef struct QueueElement QueueElement;
typedef struct Queue Queue;

Queue* createQueue();
QueueElement* createQueueElement(Queue* queue, int value);
bool isEmptyQueue(Queue *queue);
void pushToQueue(int value, Queue *queue);
void front(Queue* queue);
bool addToQueue();
char popFromQueue(Queue* queue);
int size(Queue *queue);
void deleteQueue(Queue *queue);
#endif
