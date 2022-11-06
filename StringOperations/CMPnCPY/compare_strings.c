#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
--------- Comparing strings ----------- 
*/

int main(int argc, char *argv[])
{
    char str1[] = "abcd4";
    char str2[] = "abcd1";
    char *str3 = &str1;

    printf("Memory address of str1: %p\n", str1);
    printf("Memory address of str3: %p\n", str3);

    // string compare
    int x = strcmp(str1, str2); 
    /*
    compares each byte
    returns pos value when str1 > str2
    returns neg value when str1 < str2
    returns 0 when str1 is equal to str2 (at least by value)
    */
    int y = strncmp(str1, str2, 4); // => returns 0
    /*
    strncmp(char* str1, char* str2, size_t n) compares N characters 
    */
    int z = memcmp(str1, str3, 100);
    /*
    memcmp(void* s1. void *s2, size_t n) compares N bytes
    basically same as strncmp, but ignoring null terminators
    Here, we have set str3, to point to same memry as str1
    this means, no matter size of N, memcmp will here
    always return 0
    */
    printf("Return value strcmp: %d\n", x);
    printf("Return value strncmp: %d\n", y);
    printf("Return value memcmp: %d\n", z);

    return 0;
}