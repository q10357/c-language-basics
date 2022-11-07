#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
----------- SUBTRACTING CHARS ------------
*/

int getUpperCase(char c){
    if(c >= 'a' && c <= 'z'){
        c -= 0x20;
    }else{
        printf("Not a lowercase letter");
        c = 0;
    }
    
    return c;
}

int getLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        c += 0x20;;
    }else{
        printf("Not an uppercase letter");
        c = 0;
    }
    
    return c;
}

int convertCharToNumber(char c){
    if(c >= '0' && c <= '9'){
        c -= '0';
    } else {
        printf("This is not a digit: %c\n", c);
        c = -1;
    }
    return (int)c;
}

int main(int argc, char *argv[])
{
    char x = 'e';
    char y = 'I';
    char z = '7'; //7 has ASCII code 55

    //To get capital of e
    char xUpper = getUpperCase(x);
    char yCapital = getLowerCase(y);
    char zNumRep = convertCharToNumber(z);

    printf("%c uppercase is %c\n", x, xUpper);
    printf("%c lowercase is %c\n", y, yCapital);
    printf("%c as a digit is %d\n", z, zNumRep);

    return 0;
}