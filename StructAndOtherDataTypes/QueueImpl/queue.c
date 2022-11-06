#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_utils.h"

int rand_interval(int a, int b)
{
    /*
    %i i is the size of the intervall
    if interval is 50..150, i = 150 - 50 = 100
    Which is size of interval
    */
    return rand() % (b -a) + a;
}

void peekFront(Queue* q)
{
    int front = peek(q);
    printf("In the front of the queue is: %i\n", front);
    
}

void fillQueue(Queue* q)
{
    int i = 0;
    for(i; i < 200; i++){
        enqueue(q, rand_interval(0, (200 + 1)));
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Queue q = queueCreate(256);
    fillQueue(&q);
    peekFront(&q);
    dequeue(&q);
    peekFront(&q);
    dequeue(&q);
    
    queueDestroy(&q);
    printf("We have queue: %d size\n", q.size);
    return 0;
}