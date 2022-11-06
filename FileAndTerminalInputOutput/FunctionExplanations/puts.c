#include <stdio.h>


void WriteToFile(char* pStr);

int main(int argc, char* argv[]){
    char str[] = "hello world";
    /*
    puts() prints to the stdout, it also replaces null terminator \0 
    with a \n
    this does not happen with fputs()
    To check if successfull, we can take return value, 
    if result is >= 0, it succedded printing
    */
    int res = puts(str);
    if( res > 0 ){
        printf("Success\n");
    } else {
        printf("Failure\n");
    }

    WriteToFile(str);
    return 0;
}

void WriteToFile(char* pStr){
    FILE *f;

    f = fopen("demonstratefputs.txt", "w");
    if( f != NULL ){
        //Does not add \n to end
        fputs(pStr, f);
        fputs(pStr, f);
        fputs(pStr, f);
    }else{
        printf("Error in loading file");
    }
    fclose(f);
}