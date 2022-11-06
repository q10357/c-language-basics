#ifndef POINT_UTIL_H
#define POINT_UTIL_H

typedef struct Point {
    float x, y;
} Point;

void print_point(const Point* a);
void get_middle_point(const Point* a, const Point* b, Point* out);
#endif