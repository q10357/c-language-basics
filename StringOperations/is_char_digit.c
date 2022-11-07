#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
----------- HOW TO CHECK IF BYTE/CHAR IS A DIGIT -------------------

how to check if char/byte is digit, or another value like an a, or _ etc.

*/

int main(int argc, char *argv[])
{
    char c = '5';
    //check ASCII table for explanation
    if(c >= '0' && c <= '9'){
        printf("This is a digit: %c\n", c);
    } else {
        printf("This is not a digit: %c\n", c);
    }

    return 0;
}