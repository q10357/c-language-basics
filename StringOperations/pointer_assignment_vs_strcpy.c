#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialize str and num
void create(char** str, int iSize)
{
    //we want to allocate str
    *str = malloc(sizeof(char) * iSize);
}

void process(char** str)
{
    char example[100] = "this is a test";
    
    /*
    What is the difference between the two lines of code below? 
    *str = example;
    strcpy(*str, example);
    See below under EXPLANATION 
    */
    strcpy(*str, example);
}

int main(int argc, char* argv[])
{
    char* str;
    create(&str, 100);
    process(&str);
    printf("%s\n", str);
    free(str);

    return 0;
}

/*
----------- EXPLANATION ------------

When using str = example
We will set the adress of str, to point at example.
these two variables will now have the same address in memory

*str = example;
printf("Memory address of str: %p\n", *str);
printf("Memory address of example: %p\n", example);
Both will print the same address

This is not very good, why do you ask?
So, we have set str to point to the memory address of example,
but wait, example is a local variable, defined in process()
when exiting the function, the memory that has been allocated
for example, will be deallocated.
The variable is now out of scope, out of our reach, and our str is still pointing to it!

Also, we can not free the memory we allocated for str in create(), since
we have lost our pointer to the allocated memory.

What about strcpy(str, example) then?
Here we will copy the contents of example,
into whatever str points to, without changing str pointer.

This means we will have no issue with example being out of scope,
and we will keep out pointer to the dynamically allocated memory.
Great!

*/