#include <stdio.h>
#include <string.h>

typedef struct Point {
    int x, y;
} Point;

int main(int argc, char* argv[]) {
    Point p1 = {
        .x = 13,
        .y = -5
    };

    Point p2;

    FILE *in;
    FILE *out;

    // ---WRITE---

    out = fopen("point.bin", "wb");
    if(out == NULL){
        printf("Error opening point.bin, when writing");
        return 1;
    }

    size_t elements_written = fwrite(&p1, sizeof(Point), 1, out);
    if(elements_written == 0){
        printf("Error writing to file, 0 elements");
        return 2;
    }
    fclose(out);

    // ---READ---
    in = fopen("point.bin", "rb");
    if(in == NULL){
        printf("Error opening point.bin, when reading");
        return 3;
    }

    size_t elements_read = fread(&p2, sizeof(Point), 1, in);
    fclose(in);

    if(elements_read == 0){
        printf("Error reading to file, 0 elements");
        return 4;
    }

    printf("Point read from binary file: %d, %d\n", p2.x, p2.y);


    return 0;
}