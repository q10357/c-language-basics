#include <stdlib.h>
#include <stdio.h>

//Very usefull 4real
#define POINT_FORMAT "(%.02lf, %.02lf)"

typedef struct Point {
    double x, y;
} Point;

void process(Point q){
    //...
    q.x += 5;

    Point u = {
        .x = 19.5,
        .y = 0.25
    };

    printf("My point q: "POINT_FORMAT
            " and my point u: " POINT_FORMAT"\n",
                q.x, q.y, u.x, u.y);
}

int main(int argc, char* argv[]){
    Point p = {
        .x = 10,
        .y = 25
    };

    //What if i want this string as a variable in my program
    //I can simply use snprintf
    //printf("%d %d\n", p.x, p.y);

    char buf[100];
    process(p);
    snprintf(buf, 100, POINT_FORMAT"\n", p.x, p.y);

    printf("%s", buf);

    return 0;
}