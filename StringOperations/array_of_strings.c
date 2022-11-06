#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_MAX 3

int main(int argc, char* argv[])
{
    char array[ARR_MAX][50];
    //3 strings in array, with
    //global size of sizeof(50 *(char))

    /*
    You can also write as below
    */
    char array2[ARR_MAX*50];
    
    //OR as below
    char array3[][50] = {
        "Good afternoon",
        "Stay safe",
        "Mvh"
    };
    /*
    strcpy() -> see strcpy.txt
    */
    strcpy(array[0], "Good Morning!");
    strcpy(array[1], "stay blessed");
    strcpy(array[2], "xoxo"); 

    unsigned long ulStringCount = (sizeof(array) / sizeof(array[0]));
    printf("Number of strings in array: %llu\n", ulStringCount);

    unsigned int i = 0;
    printf("Array1: \n");
    for(i; i < ulStringCount; i++){
        printf("String %i is: %s\n", i, array[i]);
    }

    //Array2
    strcpy(array2, "Good evening!");
    strcpy(array2 + 50, "stay blessed");
    strcpy(array2 + 100, "kiss kiss");

    printf("Array2: \n");
    i = 0;
    for(i; i < 150; i+=50){
        printf("String %i is: %s\n", i, array2 + i);
    }
    
    return 0;
}