#include <stdio.h>

/*
Overflow - Amount of representation a certain variable can hold
If a variable store only 1 byte, amount of representation is 2^8 = 256
We can store 256 different (0 to 255)
What if we make it store more than this?

if we make U_BYTE = 256, and print it out to console
we will se 0
why?
255 = 1111 1111 + 1 = 1 0000 0000
But char is only 1 byte, so overflow bit will be omitted
=> 0000 0000
*/

//%hhu one byte unsigned char
//%02hhX one byte unsigned char as hex, if less than 2 digit, padd w 0s
#define U_CHAR_FORMAT "(%hhu | %02hhX)"
#define CHAR_FORMAT "(%hhd | %02hhX)"
#define INT_FORMAT "(%u | %04X)"
#define PRINT_DEC_HEX(FORMAT, X) printf(FORMAT, X, X);

typedef unsigned char U_BYTE;
typedef char BYTE;

int main(int argc, char* argv[]) 
{
    int value = 250;
    U_BYTE b = value;
    int i;
    printf("unsigned char: \n");
    for(i = 0; i < 10; i++){
        PRINT_DEC_HEX(U_CHAR_FORMAT" ", b);
        b++;
    }

    //We cast b to integer
    unsigned int c = value;

    printf("\nunsigned int: \n");
    for(i = 0; i < 10; i++){
        //Will not overflow, as int is 32 bits, no bit overflow
        PRINT_DEC_HEX(INT_FORMAT" ", c);
        c++;
    }

    BYTE x = 127;
    printf("\nsigned char: \n");
    for(i = 0; i < 10; i++){
        /*
        All values over 127, will be negative numbers
        128 will become -128, since the signed bit will be 1, making it negative
        All numbers from 128 - 255 will be negative, 256 will be 0
        256 => 0001 0000 0000, overflow bit is omitted => 0000 0000
            => UNDERFLOW 
        */
        PRINT_DEC_HEX(CHAR_FORMAT, x);
        x++;
    }


    printf("\n");
    return 0;
}