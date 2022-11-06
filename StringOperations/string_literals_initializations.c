#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
String initialization can be confusing. Important to understand process

*/
int main(int argc, char* argv[])
{
    char str[] = "Hello!";
    printf("%s\n", str);

    str[0] = 'h';
    printf("%s\n", str);
    return 0;
}