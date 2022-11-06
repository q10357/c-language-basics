#include <stdio.h>

void DemonstratePutChar(int c);
void DemonstratePutC(int c);

int main(){

    /*
    Return value of all these (put functions) functions, 
    is the character written to the function
    */

    int c = getc(stdin);

    DemonstratePutChar(c);
    DemonstratePutC(c);
    
    return 0;
}

void DemonstratePutChar(int c){
    printf("Using method putchar(%c)\n", c);
    putchar(c);
    printf("\n");
}

void DemonstratePutC(int c){
    //We can write the char to a another stream, such as a file
    //fputc(c) is the equivalent, just following naming conventions
    FILE *f;

    f = fopen("putc.txt", "w");

    printf("Using method putc(%c)\n", c);
    
    putc(c, stdout);
    putc(c, f);
    fclose(f);
    printf("\n");
}