#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
String initialization can be confusing. 
Important to understand process
*/
int main(int argc, char* argv[])
{
    //char *str = "Hello";
    //char str[] = "Hello";

    /*
    If you want a modifiable array,
    while still initializing with char*
    see below
    */

    char *str = malloc(20*sizeof(char));
    strcpy(str, "Hello");
    printf("%s\n", str);

    str[0] = 'h';
    printf("%s\n", str);
    /*
    This works!
    If you allocate it dynamically, you can change str[n]
    */
    free(str);
    return 0;
}

/*
So, you can initialize a string both by 
char[] and pointer reference char* 
So what is the difference?

When initializing with pointer (char*), 
if we try str[0] = 'h', code that worked 
fine when we initialized the str by char[],
will result in a Segmentation Fault.

Why ?
1. char str[] = "Hello";
2. char str[] = { 'H', 'e', 'l', 'l', 'o'};
1 and 2 are equivalent. 
1 is syntactic sugar 2.

3. char* str = "Hello";
4. const static char noname[]= "Hello";
    char *str = noname;
3 and 4 are equivalent
3 is syntactic sugar for 4.

C does not allocate "Hello!" as a string literal.
It allocates it on the function's stack (here main).
char *str, C will allocate memory, some place
that may not have read/write permissions.

https://bytes.com/topic/c/answers/219280-why-char-p-can-not-modiy-char-p-can-modify

Basically, 
str[sizeof("Hello") + 1];
strcpy(p, "Hello");
^ an array of chars, with known size
("hello" + null terminator)
While char* str = "Hello" 
*/