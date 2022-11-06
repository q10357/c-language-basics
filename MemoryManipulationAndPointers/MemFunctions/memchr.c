#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char str[] = "Isabel Chaparian";
    const char ch = 'C';
    char *ret;

    ret = memchr(str, ch, strlen(str));

    printf("String after |%c| is - |%s|\n", ch, ret);

    int arr1[] = { 3, 4 };
    int arr2[] = { 1, 2 };

    if(memchr(arr1, 0, sizeof(int)* 2) != NULL){
        printf("Found the byte \n");
    } else {
        printf("Did not find the byte\n");
    }
    return 0;
}
/*
The C library function void *memchr(const void *str, int c, size_t n) 
searches for the first occurrence of the character c (an unsigned char) 
in the first n bytes of the string pointed to, by the argument str.

Declaration

Following is the declaration for memchr() function.

void *memchr(const void *str, int c, size_t n)

Parameters

    str − This is the pointer to the block of memory where the search is performed.

    c − This is the value to be passed as an int, 
        but the function performs a byte per byte search 
        using the unsigned char conversion of this value.

    n − This is the number of bytes to be analyzed.


Return Value

This function returns a pointer to the matching byte 
or NULL if the character does not occur in the given memory area.
*/