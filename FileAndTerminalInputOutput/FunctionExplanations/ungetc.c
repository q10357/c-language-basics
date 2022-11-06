#include <stdio.h>


void f(){
    char c = getchar();
    printf("Again the same result: %c\n");
}

void UseInFile();

int main() {
    char c = getchar();
    printf("Result: %c\n", c);

    /*
    What if we have another function, that does a different thing,
    and we want to let it use getchar() and read the same character

    Inside each file, you have a counter that says at which 
    character you are at in the file.
    getchar() reads the next character in line, which is the c from input(keyboard)
    ungetc(int c, stream), makes counter go one back, and lets our character 
    back in the stream
    You can do it with any filehandler. ungetc does not write to the standard input.

    https://www.geeksforgeeks.org/ungetc-in-c-c/ GOOD EXAMPLE

    returns character written as an int
    */
    int res = ungetc(c, stdin);

    f();
    UseInFile();
    return 0;
}

void UseInFile(){
    FILE *f;

    char str[256] = "!sabel loves Ice Cream.";
    char buffer[256];
    f = fopen("poem.txt", "w+");
    if(f == NULL){
        return 1;
    }
    
    int bytes_wrote = fprintf(f, "%s", str);
    
     if(bytes_wrote <= 0){
        printf("Error Writing\n");
        return 2;
    }

    fseek(f, 0, SEEK_SET);
    char c;
    // -- READ, WRITE AND MANIPULATE --
    while(!feof(f)){
        int c = getc(f);

        if((char)c == '!' ){
            ungetc('I', f);
        }

        else {
            ungetc(c, f);
        }
        
        fgets(buffer, 255, f);
        //Back to start
        rewind(f);
        fputs(buffer, f);;
    }
    fclose(f);
}