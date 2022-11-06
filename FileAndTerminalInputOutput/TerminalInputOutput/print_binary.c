#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a = 13;

    printf("Decimal: %d\n", a);
    printf("Hexadecimal: %08x\n", a);
    /*
    How to print binary
    */
    long long i, j;
    for(i = 0; i < sizeof(int); i++){
        // Same as below: char byte = *(((char*)&a) + i);
        /* 
        Take memory address of a, cast it to char*, now 1 byte
        and move to i 
        */
        char byte = ((char*)&a)[i];
        for(j = 8; j >= 0; j--){
            char bit = (byte >> j) & 1;
            printf("%hhd", bit);
            //byte >>= 1;
            /*
            1101 >> 1;  => 110 (bitshifted to the right)
            1101 & 0001;  => 0001 (because 1101 last digit is 1)
            */ 
        }
        printf(" ");
    }
    printf("\n");

    return 0;
}