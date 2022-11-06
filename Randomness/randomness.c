#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

/*
This will produce same numbers each time...? why
whenever it starts a new program, the sequence of random numbers that it gives
is always the same, how can we make the program produce different numbers
each time we execute the program
well.. so what is different every time we run the program.......
AHA, TIME!
so we use time as a seed when generating a random number BRILLIANT!
*/
    time_t secondsFromEpoch = time(NULL);
    srand(secondsFromEpoch);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;

}