#include <stdio.h>
#include <stdlib.h>
#include "point_utils.h"

int main(int argc, char *argv[])
{
    Point p1 = {
        .x = 0.78,
        .y = 1.24
    };

    Point p2 = {
        .x = 2.55,
        .y = 1.88
    };

    /*
    We want to have a function that get's the middlepoint in a line
    */

    Point middle;
    get_middle_point(&p1, &p2, &middle);
    printf("The Middle Point Is ");
    print_point(&middle);
    return 0;
}
