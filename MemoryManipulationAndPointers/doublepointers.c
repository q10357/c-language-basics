#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
YOU CAN CHANGE VALUE OF POINTER YOU ARE POINTING AT
*/
void display(char** output){
    printf("%s\n", *output);
    //TADA now str in main is changed
    //Now pointing at another value
    *output = "This is another test";
}

int main(int argc, char* argv[]){
    char* str = "This is a test";
    display(&str);
    printf("After the call: %s\n", str);
    return 0;
}