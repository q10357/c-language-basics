#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
    int res = rename("currentName.dat", "updatedName.dat");

    if(res == 0){
        printf("File renaming successfull!\n");
    } else {
        printf("Failed to rename file with error: %s!\n", strerror(errno));
    }

    return 0;
}