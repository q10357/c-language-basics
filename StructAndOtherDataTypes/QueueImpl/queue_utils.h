#ifndef QUEUE_UTIL_H
#define QUEUE_UTIL_H

typedef struct Queue {
    int capacity;
    int size;
    int front;
    int rear;
    int *elements;
} Queue;

Queue queueCreate(int maxElements);
void queueInsert(int* queue, int elem, int qSize);
void queueDestroy(Queue* q);
int peek(Queue* q);
void enqueue(Queue* q, int element);
void dequeue(Queue* q);
#endif