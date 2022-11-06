#include <stdio.h>

int main(int argc, char* argv[]){
    char str[10];
    int v = 0;

    //gets(str); UNSAFE
    fgets(str, 10, stdin); //SAFER
    /*
    An important detail: In the end, the \n(enter) does not get copied into the buffer, 
    instead a null terminator gets copied \0, so basically
    the \n gets replaced with a \0 terminator


    */
    printf("You typed: %s\n", str);
    printf("v: %d | %x\n", v, v);
    return 0;
}