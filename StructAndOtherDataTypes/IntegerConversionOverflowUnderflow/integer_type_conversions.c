#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    short int x = 16384;
    //2 bytes

    int y = 1073741825;
    //4 bytes => 0100 0000  0000 0000  0000 0000  0000 0001

    /*
    When printing x to console, we get 1
    This is because x is only 32 bits, so it will recieve the last 32 bits
    If y = 1073741824, and x = y, x will be 0
    since y = 0100 0000  0000 0000  0000 0000  0000 0000
    last 32 bits all 0s
    */
    x = y;
    //hd => short int
    printf("%hd %d\n", x, y);


    /*
        ----------- NB: NEGATIVE NUMBERS -------------
    */
    x = -16384;
    // 1100 0000  0000 0000
    /*
    When making it into a negative number, all we need to do (bitwise),
    is to set the signed bit to 1
    */

    y = x;
    /*
    When we set y, a 4 byte datatype, to be equal to x, a 2 byte datatype
    y will still be og size 4 bytes, most significant bytes will be paded.
    The padding will be same as signed bit. Signed bit is set to 1 if negative
    result y: 
    1111 1111  1111 1111  1100 0000  0000 0000
    */
    printf("%hd %d\n", x, y);

    /*
    When we print out, they have the same value
    */

    return 0;
}