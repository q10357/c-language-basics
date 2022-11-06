#include <stdio.h>

/*
Some may use macros
#define RED 1
#define BLUE 2
#define ISABEL 6 etc...
but it's nice to have a type
*/

//Enums in c
//NB: All values inside enumerations are gonna be made into integers

typedef enum Color {
    RED,
    BLUE
} Color;

/*
This is stupid, but made to show that you can
Manually set the values of enum members.

If we didnt set any value to MARIT, it's value would be ++ISABEL = 7 
*/
typedef enum Name {
    ISABEL = 6,
    MARIT = 5
} Name;

int main(int argc, char* argv[])
{
    Color a = RED;
    Color b = BLUE;

    /*
    When not defined manually, will print out the order placement of the value in the enum
    aka RED = 0, BLUE = 1
    */
    printf("Value red: %d\n", a);
    printf("Value blue: %d\n", b);

    /*
    In the enum Name, we sat the values manually, to being the length of the names
    so here we will get ISABEL = 6, MARIT = 5
    */

    Name name1 = ISABEL;
    Name name2 = MARIT;
    printf("Value ISABEL: %d\n", name1);
    printf("Value MARIT: %d\n", name2);


    return 0;
}