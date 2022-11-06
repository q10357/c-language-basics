#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Copy 
int main(int argc, char *argv[]){
    int arr1[] = { 3, 4 };
    int arr2[] = { 1, 2 };

    printf("Size of arr1 before copy: %d\n", sizeof(arr1));
    memcpy(arr1 + 2, arr2, 2 *  sizeof(int));

    //Copies memory from one place to another, n many bytes
    printf("Size of arr1 after copy: %d\n", sizeof(arr1));

    for(int i = 0; i < (sizeof(arr2) /sizeof(int)); i++){
        printf("This is element %d: %d\n", i, arr1[i]);
        printf("This is element arr1[i+1]: %d\n", arr1[i + 1]);
    }

    return 0;
}

/* 
The C library function void *memcpy(void *dest, const void *src, size_t n) 
copies n characters from memory area src to memory area dest.
AD
Declaration

Following is the declaration for memcpy() function.

void *memcpy(void *dest, const void * src, size_t n)

Parameters

    dest − This is pointer to the destination array where the content is to be copied, 
            type-casted to a pointer of type void*.

    src − This is pointer to the source of data to be copied, 
            type-casted to a pointer of type void*.

    n − This is the number of bytes to be copied.

AD
Return Value

This function returns a pointer to destination, which is str1.
*/