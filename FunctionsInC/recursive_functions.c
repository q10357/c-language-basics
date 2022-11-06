#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//4 => 4 + 3 + 2 + 1 = 10
int f(int x)
{   
    if(x < 0){
        printf("X is now 0\n");
        return 0;
    }
    printf("Hello from f with x = %d\n", x);
    return x + f(x - 1);
}

int main(int argc, char* argv[])
{
    int result = f(4);
    printf("The result of calling f is %d\n", result);
    return 0;
}