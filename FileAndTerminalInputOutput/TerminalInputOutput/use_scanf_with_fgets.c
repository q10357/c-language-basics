#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    int id;
    char message[256];

    /*
    scanf() when reading strings, is not very smart...
    it will read string up until it finds a whitespace or a \n or an EOF

    fgets() gets a whole line of text until a \n or an EOF
    ignores whitespace 
    */
    while(1) {
        printf("Input ID: ");
        scanf("%d", &id);
        int c = fgetc(stdin);
        printf("Input message: ");
        fgets(message, 256, stdin);
        //To get red of \n at end of array, make it null terminator
        message[strlen(message) - 1] = '\0';
        printf("(%d) Sent message: %s\n", id, message);
    }

    return 0;
}