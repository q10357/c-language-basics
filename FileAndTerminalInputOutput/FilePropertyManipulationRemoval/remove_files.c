#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
    int res = remove("nameoffile.dat");

    if(res == 0){
        printf("Removed file successfully!\n");
    }else{
        printf("Failed to remove file with error: %s!\n", strerror(errno));
    }

    return 0;
}