#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_interval(int a, int b)
{
    /*
    %i i is the size of the intervall
    if interval is 50..150, i = 150 - 50 = 100
    Which is size of interval
    */
    return rand() % (b -a) + a;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    //Numbers from 0..99
    //rand() % 100;

    /*
    What if we want our interval to not start at 0
    we want from 50..149 example

    [0, 10] + 4 => [4, 14]
    2 + 4 = 6
    0 + 4 = 4
    10 + 4 = 14
    */
    rand() % 100 + 50;

    for( int i = 0; i < 100; i++){
        //Will only print out numbers x..y
        int x = 5;
        int y = 20;
        printf("%d ", rand_interval(x, y));
    }

    printf("\n");
    return 0;
}