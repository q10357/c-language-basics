#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Each variable can be accessed based on the scope they are used
Every single function defines it's own scope, and then
there is the global scope which encompasses whole program.

Globals can be very buggy, avoid using them
*/
int y = 5;

void f1(){
    int x;
    if(y == 5){
        x = 10;
    }else{
        x = 15;
    }

    printf("Value of x is %d\n", x);
}

int main(int argc, char* argv[])
{
    f1();
    return 0;  
}