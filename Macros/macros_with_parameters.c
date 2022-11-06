#include <stdio.h>
#include <stdlib.h>

/*
convention is to have uppercase letters in macros in C
*/
#define PRINT_VAR(X)\ 
    printf(#X " is %d\nAdress is %p\n", X, &X);

int main(int argc, char* argv[]){
    int a = 3;
    PRINT_VAR(a);
    
    return 0;
}