#include <stdio.h>
#include <stdlib.h>

#define POINT_FORMAT "(%.02f, %.02f)"
/*
    What is typedef, and what does it do in this situation?

    Defition: You can give other names to a data type
    Let's say you have a program that works a lot with numbers 
    of type 
    unsigned long long
    It may not be very practical to write this before all your variables,
    return types etc.
    What to do.....???!?

    You can typedef it!
    Look below
*/

typedef unsigned long long UINT64;

/*
    We can also typedef user made data types, such as Point
*/
typedef struct Point {
    float x, y;
} Point;

int main(int argc, char *argv[])
{
    //Instad of writing unsigned long long = 14
    //You are now allowed to do this!

    UINT64 l = 14;

    Point p = {
        .x = 0.78,
        .y = 1.24
    };

    char* buff[100];

    printf("%llu\n", l);
    printf("My point p: "POINT_FORMAT"\n", p.x, p.y);

    //Store in variable buff
    snprintf(buff, 100, POINT_FORMAT"\n", p.x, p.y);
    printf("We now have saved point as string: %s\n", buff);
    return 0;
}
