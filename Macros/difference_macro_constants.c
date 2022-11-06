#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define PATTERN "My name is "
/*
What is the difference betweeen constants and macros?
Preproccessor takes all # with hastag, and do operations on the code before compiling
It will copy/paste the MAX names with the value we have defined above

Next phase is compilation phase. 
*/
int main(int argc, char* argv[])
{
    int arr[MAX];
    printf(PATTERN"Bob\n");
    return 0;
}