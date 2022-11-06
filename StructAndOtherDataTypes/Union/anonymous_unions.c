#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CustomFloat {
    union {
        /*
        Both stored in same place in memory
        Either 32 bits, or 64 bits... but which one?
        That's where the struct comes in
        */
        float value;
        double valueExtended;
    };
    bool isExtended;
} CustomFloat;

int main(int argc, char* argv[])
{
    CustomFloat cf1, cf2;
    cf1.isExtended = false;
    cf1.value = 12.5;

    cf2.isExtended = true;
    cf2.valueExtended = 0.25;
    printf("cf1: %f %lf\n", cf1.value, cf1.valueExtended);
    //cf2.value is garbage value, since we initialized with valueExtended
    //we cannot read the 8 byte float in 4 bytes
    printf("cf2: %f %lf\n", cf2.value, cf2.valueExtended);

    /*
    Below we print the place in memory for the members .value .valueExtended
    As you see in the console, they point to the same memory
    */
    printf("Memory of union members cf1: %p %p\n", &cf1.value, &cf1.valueExtended); // => same
    printf("Memory of union members cf2: %p %p\n", &cf2.value, &cf2.valueExtended); // => same


    /*
    Well, they use the same amount of space... so why bother?
    */
    printf("Size of cf1: %llu\n", sizeof(cf1));
    printf("Size of cf2: %llu\n", sizeof(cf1));

    /*
    Well, in a place where you need this kind of variables- We could have 10 custom floats
    where 5 are 32 bits, while others are 64 bits.
    We are still gonna use the same amount of memory for the union, as it allocates
    memory to fit the largest datatype.
    The advantage is, that you can technically take it all together
    and copy it straight from memory, to another place of memory, without worrying
    about referances.
    */

    return 0;
}

/*

Picture this:

I want a data type that can store a simple 32 bit float.
But sometimes i want it to store 64 bit floats/ doubles

How can we achieve that, within the same datatype?
Well, we can do so, using the concept of anonymous unions
*/