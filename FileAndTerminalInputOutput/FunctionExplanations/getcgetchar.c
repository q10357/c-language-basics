#include <stdio.h>

int main() {

    /*
    getchar() is equivalent to getc(stdin), just with no parameters
    */
    int c = getc(stdin);
    printf("Printed char as hex: %02x\n", c);
    printf("Printed char: %c\n", c);
    
    return 0;
}

/*
Description

The C library function int getc(FILE *stream) gets the next character (an unsigned char) 
from the specified stream and advances the position indicator for the stream.

int getc(FILE *stream)

Parameters

    stream − This is the pointer to a FILE object that identifies the stream 
    on which the operation is to be performed.


Return Value
This function returns the character read as an unsigned char 
cast to an int or EOF on end of file or error.

*/