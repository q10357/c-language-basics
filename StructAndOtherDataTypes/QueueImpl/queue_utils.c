#include <stdio.h>
#include <stdlib.h>
#include "queue_utils.h"

Queue queueCreate(int maxElem)
{
    Queue pQ = {
        .elements = (int*)malloc(sizeof(int)*maxElem),
        .size = 0,
        .capacity = maxElem,
        .front = 0,
        .rear = -1
    };
    
    return pQ;
}

void dequeue(Queue* q)
{
    if(q->size==0){
        printf("Queue is Empty\n");
        return;
    }else{
        q->size--;
        q->front++;
        //Fill elements in circular fashion
        if(q->front==q->capacity)
        {
            q->front = 0;
        }
    }
    return;
}

void queueDestroy(Queue* q)
{
    free(q->elements);
    q->elements = NULL;
}

void enqueue(Queue *q, int element)
{
    if(q->size == q->capacity){
        printf("Queue is Full\n");
        return;
    }
    q->size++;
    //Possible w q->rear++; ?...
    q->rear = q->rear + 1;
    //Fill the queue in circular fashion
    if(q->rear == q->capacity){
        q->rear = 0;
    }
    q->elements[q->rear] = element;
}

int peek(Queue *q)
{
    if(q->size == 0){
        printf("Queue is Empty\n");
        exit(0);
    }
    /* Return the element which is at the front */
    return q->elements[q->front];
}
