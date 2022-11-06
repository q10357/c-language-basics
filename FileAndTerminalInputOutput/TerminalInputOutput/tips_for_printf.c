#include <stdio.h>
#include <stdlib.h>

void AllignNumbersInPrintf(int* a, int* b);
void PlayWithAddresses(int* a, int*b);

int main(int argc, char *argv){
    long long a = 255;

    /*use %u for unsigned integer*/
    //printf("%u\n", a);

    /*
    sizeof() returns 64 bit unsigned long, use %llu 
    */

    printf("%llu\n", sizeof(a));

    float x = 2.55;

    /*
    After dot, print only .2 digits of the number
    */
   int z = 255, y = 1500;
    printf("%.02f\n", x);
    PlayWithAddresses(&z, &y);

    return 0;
}

void AllignNumbersInPrintf(int* a, int* b){
int c, d;
c = *a;
d = *b;
    /*
    This will print witout padding, how can we allign the numbers?
    printf("%d\n%d\n", a, b);
    */

   /*set left padding of spaces*/
   printf("%8d\n%8d\n", c, d);

   /*You can also padd with 0*/
   printf("%08d\n%08d\n", *a, *b);
   //same output
   printf("%08d\n%08d\n", c, d);

    /*Print in hexadecimal, here print max 4, pad with 0s*/
    printf("%04x\n%04x\n", *a, *b);
}

void PlayWithAddresses(int* a, int* b){
    int c, d;
    c = *a;
    d = *b;
    /*Print addresses*/
    printf("-----------------------------\n");
    printf("Playing with addresses\n");
    /*Not same addresses*/
    printf("%p\n", &a);
    printf("%p\n", &c);

    /*
    but same values, because c = *a
    */
    printf("a is: %d\n", *a);
    printf("c is: %d\n", c);

    c = 100;
    printf("a is: %d\n", *a);
    printf("c is: %d\n", c);
}