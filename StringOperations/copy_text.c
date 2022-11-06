#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int argv[])
{
    char text1[50];
    char text2[] = "temp";
    //Let's play a bit with, omitting terminator of text3
    char text3[12] = "Hello to you";

    strcpy(text1, text3);
    printf("Memory address text2: %p\n", &text2);
    printf("Memory address text3: %p\n", &text3);
    
    //strncpy(text1, text3, strlen(text3) + 1);

    /*
    Memory address of text3 is < than text2
    when reading text3, which is defined to be 12 bytes
    with no null terminator ('/0'), the program will
    continue to read from memory, reading value from text2,
    and quit reading when seeing text2's null terminator
    This results in our program copying both text3 and text1 into text1 
    */
    printf("%s\n%s\n%s\n", text1, text2, text3);

    return 0;
}