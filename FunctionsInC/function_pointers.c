#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int sum(int x, int y)
{
    return x + y;
}

int prod(int x, int y)
{
    return x * y;
}

void shouldNotBeChanged(int (*operation)(int, int)){
    srand(time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;

    printf("The result of the operation between %d and %d is %d\n",
        a, b, operation(a, b));

}

int main(int argc, char* arvg[])
{
    //we wanna manipulate random numbers
    //see ../Randomness/randomness.c for explanation of generating random numbers
    shouldNotBeChanged(prod);
    shouldNotBeChanged(sum);

    return 0;
}