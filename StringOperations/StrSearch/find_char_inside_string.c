#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
--------- SEARCH FOR CHAR IN STRING --------------
*/

int main(int argc, char *argv[])
{
    char str[] = "Hello there";
    char c = ' ';

    char *res = strchr(str, c);
    if (res)
    { // if strchr ! return NULL
        printf("Character was Found!\n");
        int cPos = res - str;
        printf("%c has the %d'nth positin in array.\n", c, cPos);
    }
    else
    {
        printf("Character was Not Found!\n");
    }
    /* strchr(char *str, int __c)
        => returns pointer to the first occurance of c in str, NULL if not found
    */
}

/*
Description

The C library function char *strchr(const char *str, int c)
searches for the first occurrence of the character c (an unsigned char)
in the string pointed to by the argument str.

Declaration

Following is the declaration for strchr() function.

char *strchr(const char *str, int c)

Parameters

    str − This is the C string to be scanned.

    c − This is the character to be searched in str.


Return Value

This returns a pointer to the first occurrence of the character c in the string str,
or NULL if the character is not found.

*/