#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int test; //4
    char k; //1
    char str[10]; //10
    int* p; //8
    short sh; //2
    // = 25, but sizeof(thing) = 32, why?
} Thing;

int main(int argc, char *argv[]) {
    /*
    Lets find the size of the struct
    */

    int i;

    Thing t = { 12, 'k', "testing", &i, 256};

    /*sizeof() return 64bit unsigned integer*/  
    printf("%llu\n", sizeof(t));

    unsigned char data;

    for(i = 0; i < sizeof(t); i++){
        if(i % 4 == 0){
            printf("\n");
        }
        data = *(((unsigned char*)&t) + i);
        printf("%02x ", data);

    }

    return 0;
}