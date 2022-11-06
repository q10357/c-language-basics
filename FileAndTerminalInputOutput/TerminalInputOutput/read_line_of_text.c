#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* 
    -----HACKY -------
    char text[100];
    printf("Type a line of text here: ");
    //%[^\n] read everything up until enter
    scanf("%[^\n]s", text);
    //We need to read the \n, if not 
    //the next scanf will stop because next character is \n
    getchar();

    printf("This is text: %s\n", text);
    printf("Type a line of text here: ");
    char text2[100];
    //%[^\n] read everything up until enter
    scanf("%[^\n]s", text2);
    getchar();

    printf("This is text: %s\n", text2);
    */
    char text[100];
    printf("Type a line of text here: ");
   /*
   fgets(void* dest, int howManyCharacters, input)
   Use fgets() for reading line of text
   */

    fgets(text, 100, stdin);
    //remove the enter 
    text[strlen(text) -1] = '\0';

    for(int i = 0; i <= strlen(text); i++){
        printf("%d ", *(text + i));
    }

    printf("\n");

    printf("This is text: %s\n", text);
    return 0;
}