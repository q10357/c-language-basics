#include <stdio.h>
#include <stdlib.h>

typedef struct arrayStack 
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack stackCreate(int cap)
{
    Stack s = {
        .top = -1,
        .capacity = cap,
        .array = (int*)malloc(sizeof(int) * cap)
    };
    
    return s;
}

//Check is stack is empty
int empty(Stack* s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int full(Stack* s)
{
    if(s->top == (s->capacity - 1))
        return 1;
    else
        return 0;
    
}

int push(Stack* s, int element)
{
    if(full(s)){
        //Stack is full
        return -1;
    }else{
        //Push to stack
        s->top++;
        s->array[s->top] = element;
        return 0;
    }
}

int pop(Stack* s)
{
    if(empty(s)){
        return -1;
    }

    return s->array[s->top--];
    //Possible error: use =>
    //s->top--;
}

int main()
{
    int choice;
    int elem;
    int res;
    Stack stack = stackCreate(5);
    Stack *pStack = &stack;

    while(1)
    {
        printf("\n 1. push");
        printf("\n 2. pop");
        printf("\n 3. exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                //Push
                printf(" enter a number \n ");
                scanf("%d", &elem);
                res = push(pStack, elem);
                if(res == -1){
                    fprintf(stderr, " stack is full \n");
                }
                break;
            case 2:
                //Pop
                elem = pop(pStack);
                if(elem == -1){
                    fprintf(stderr, " stack is empty ");
                }else{
                    printf(" popped value is %d ", elem);
                }
                break;
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}