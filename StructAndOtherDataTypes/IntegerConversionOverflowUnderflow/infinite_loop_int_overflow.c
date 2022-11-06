#include <stdio.h>

int main(int argc, char* argv[])
{
    int arr[256];
    /*
    Hmmmm... well, we will iterate until 256
    We can store 255 in an unsigned char! we will save space
    */
    unsigned char i;
    //OHNO! Infinite loop! WHY?
    for(i = 0; i < 256; i++){
        arr[i] = -5;
        printf("%d ", arr[i]);
    }
    /*
    Integer overflow!
    when i = 255, no overflow
    when i = 256, i = 0
    0001 0000 0000 => bit overflow => 0000 0000
    i is never 256! Loop is infinite
    i can never be higher than 255

    Good solution here: make i a short. Short has 2 bytes
    less likely to overflow, while still 2 bytes cheaper than using int
    */
    return 0;
}