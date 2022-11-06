#include <stdio.h>
#include <stdlib.h>

/*
void pointer basically says,
You can give me any kind of pointer,
int pointer, long long pointer, whatever,
and im gonna try to make sense of it 
*/

void printBytes(void* arr, int n){
    int i;
    for(i = 0; i < n; i++){
        //Print if in hexadecimal format 
        //And print it in 2 characters,
        //and print 0 instead of empty spaces
        //Can not dereference void pointer, so cast it to char then it will be one byte
        printf("%02x ", ((char*)arr)[i]);
    }
}

int main(int argc, char *argvv[]) {
    long long arr[] = { 16, 31, 32, 65 }; //32 bytes
    printBytes(arr, 4 * sizeof(long long));
    return 0;
}