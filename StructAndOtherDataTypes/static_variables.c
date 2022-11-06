#include <stdio.h>
#include <stdlib.h>

int add(int x) {
    /*
    When called more than once, sum != null, it will remember the last value
    See below, under EXPLANATION
    */
    static int sum = 0;
    sum += x;
    return sum;
}

int main(int argc, char* argv[])
{
    printf("%d\n", add(5));
    printf("%d\n", add(5));
    printf("%d\n", add(5));

    return 0;
}


/*
    -----------EXPLANATION-------------
    Static says, to any variable, "This variable is special, so initialize it when starting
    the program, allocate space, everything, whenever you start the program. 
    When you execute it, you don't reinitialize it, you just find it in memory.
    It's 0 first time, then add to the sum. 
    The second time, it has kept the value from first function call, 
    and will add from here.
    What static does to a variable simply: It kind of makes it global...
    Except for, you cannot access it outside it's scope
*/