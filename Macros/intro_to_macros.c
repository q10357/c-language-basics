#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

/*
Parameterize macro
NOT A FUNCTION, just COPY/PASTE into code
You don't have to define type, you can use it with 
Ints, longs, chars, whatever
*/
#define PRODUCT(X, Y) X * Y

//Parantheses are important
#define PRODUCTv2(X, Y) (X) * (Y)

/*
Why use macros instead of constants see *below, 
writing this instead procudes the same result. 
Or as a global, see *2 below, same result here also.
The difference between local/global variables and macros is:
When using a variable, youre saying, use this place in memory, dereference it 
and use it. 
With a macro, we are going to be using the pre-processor step, which is a step which happens
before the compilation. Pre prossecor will shift out all instances we have used macros 
in the code BEFORE the compilation. 
You don't have to use a space in memory, it's basically COPY/PASTE
It looks better, and uses less resources. 

Well thats cool and all.. what else
You can parameterize a macro. 
*/

//int SIZE = 5
int main(int argc, char *argv[]){
    //int SIZE = 5;
    int arr[SIZE];
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = i * 2;
    }
    for(i = 0; i < SIZE; i++){
        printf("%d", arr[i]);
    }

    printf("\n");

    int a = 2, b = 6;

    //Before compile time PRODUCT(a, b)
    //Will be switched out with a * b ( X * Y )
    printf("%d\n", PRODUCT(a, b));

    /*
    BE CAREFUL WITH MACRO PARAMETERS
    you may think this will be (a + 1 ) * b
    It's not, running this code will result in 8
    Before compiling, the pre processor will paste in
    printf("%d\n", PRODUCT(a + 1 * b)) => 8!;
    */
    printf("%d\n", PRODUCT(a + 1, b));

    /*
    This will result in 18
    Pre processor will paste in 
    printf("%d\n", (a + 1) * (b));
    */
    printf("%d\n", PRODUCTv2(a + 1, b));
    

    return 0;
}