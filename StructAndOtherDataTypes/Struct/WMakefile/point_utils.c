#include <stdio.h>
#include "point_utils.h"

#define POINT_FORMAT "(%.02f, %.02f)"

void print_point(const Point* a)
{
    char buff[100];

    //printf("My point p: "POINT_FORMAT"\n", a.x, b.y);

    //Store in variable buff if you'd like
    snprintf(buff, 100, POINT_FORMAT"\n", a->x, a->y);
    printf("Point: %s", buff);

}

void getMiddlePoint(const Point* a, const Point* b, Point* out){
    out->x = (a->x + b->x) / 2;
    out->y = (a->y + b->y) / 2;
}