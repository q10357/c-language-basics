#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Compare two places in memory
int main(int argc, char *argv[]){
    int arr1[] = { 1, 2 };
    int arr2[] = { 1, 2 };

    printf("Comparing int arrays\n");
    if(memcmp(arr1, arr2, 2 * sizeof(int)) == 0){
        printf("Arrays are the same \n");
    } else {
        printf("Arrays are not the same \n");
    }

    
    //What is one array is int and one is short??
    int arr3[] = { 1, 2 }; 
    short int arr4[] = { 1, 2 }; 

    /*
        When comparing, we take sizeof(short int)
        We will then only compare first two bytes of arr3, which is half of 1, 2 is ignored
        int is 4 bytes, short int is 2 
        s2 * sizeof(short int) = 16 * 2 = 32 bits to compare below

        arr3 32 bit per (4 bytes) first 4 bytes = 
        0000 0000  0000 0000  0000 0000  0000 0001

        arr4 16 bit per (2 bytes) first 4 bytes = 
        0000 0000  0000 0001  0000 0000  0000 0010 

        != same
    
    */
    printf("\nComparing int[] and short[]\n");
    if(memcmp(arr3, arr4, 2 * sizeof(short int)) == 0){
        printf("Arrays are the same\n");
    } else {
        printf("Arrays are not the same \n");
    }
    
    return 0;
}

/*

int memcmp(const void *str1, const void *str2, size_t n)

Parameters

    str1 − This is the pointer to a block of memory.

    str2 − This is the pointer to a block of memory.

    n − This is the number of bytes to be compared.

AD
Return Value

    if Return value < 0 then it indicates str1 is less than str2.

    if Return value > 0 then it indicates str2 is less than str1.

    if Return value = 0 then it indicates str1 is equal to str2.

*/