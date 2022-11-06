#include <stdio.h>
#include <stdlib.h>

#define SWAP(A, B) A ^= B ^= A ^= B;

int main(int argc, char* argv[])
{
    int a = 3, b = 8;
    //a ^= b ^= a ^= b;
    SWAP(a, b);
    printf("a is %i\nb is %i\n", a, b);

    return 0;
}