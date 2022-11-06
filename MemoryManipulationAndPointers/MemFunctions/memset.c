#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int arr1[] = { 3, 4 };
    int arr2[] = { 1, 2 };

    //void *memset(void *ptr, int x, size_t n);
    memset(arr1, 2, 2 * sizeof(int));

    /*
    Set 2 * 4 bytes to value 001, here:
    0000 0010  0000 0010  0000 0010  0000 0010 = 33686018
    */
    //%08x for hex
    printf("%08x %08x\n", arr1[0], arr1[1]);

    printf("%d %d\n", arr1[0], arr1[1]);

}
/*memset() is used to fill a block of memory with a particular value.
The syntax of memset() function is as follows :

// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting 
//         from ptr to be filled
void *memset(void *ptr, int x, size_t n);
*/