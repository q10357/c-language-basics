#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
How can be implement generics, without any object-oriented features
like in c++, java etc?

There is the void pointer!
*/
typedef enum {
    STACK_INT,
    STACK_CHAR,
    STACK_UINT64 // -> unsigned long long (62bit integer);

} StackDatatype;

typedef struct Stack {
    StackDatatype type;
    //use size_t with 
    size_t size;
    void* data;
    void* top;
} Stack;

Stack stack_create(size_t size, StackDatatype type)
{
    size_t effectiveSize = 0;
    if (type == STACK_CHAR){
        effectiveSize = size * sizeof(char);
    } else if (type == STACK_INT){
        effectiveSize = size * sizeof(int);
    } else if (type == STACK_UINT64){
        effectiveSize = size * sizeof(unsigned long long);
    } 
    
    Stack s = {
        .type = type,
        .size = size,
        .data = malloc(effectiveSize),
        .top = NULL
    };

    return s;
}

/*void stack_push(Stack* s, void* elem)
{

}
*/

void stack_delete(Stack* s){
    free(s->data);
    //Dealocated, now set to NULL
    s->data = NULL;
}

int main(int argc, char* argv[])
{
    Stack s = stack_create(10, STACK_INT);
    ((int*)s.data)[0] = 42;
    //Cannot add to null pointers, have to cast
    s.top = ((int*)s.data) + 0;

    ((int*)s.data)[1] = 128;
    s.top = ((int*)s.data) + 1;
    stack_delete(&s);
    return 0;
}

