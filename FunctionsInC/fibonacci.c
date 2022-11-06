#include <stdio.h>
#include <stdlib.h>

int fibonacci(int k){
    int n1, n2, x;
    int i;
    n1 = 0;
    n2 = 1;
    if(k == 1){
        return n1;
    }
    for(i = 0; i < k - 2; i++){
        x = n2;
        n2 = n1 + n2;
        n1 = x;
    }
    return n2;
}

int main(int argc, char * argv[])
{
    int fib = fibonacci(10);

    printf("The nth number is %i\n", fib);
    return 0;
}