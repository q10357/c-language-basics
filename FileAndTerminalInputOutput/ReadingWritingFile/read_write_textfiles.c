#include <stdio.h>
#include <string.h>

typedef struct Point {
    int x, y;
} Point;

int main(int argc, char* argv[]) {
    Point p1 = {
        .x = 12,
        .y = -9
    };

    Point p2;

    FILE *file;

    // --- WRITE ----

    file = fopen("point.txt", "w+");
    if(file == NULL) return 1;

    //sprintf(buffer_out, "%d, %d\n", p1.x, p1.y);
    //size_t bytes_wrote = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
    int bytes_wrote = fprintf(file, "%d, %d\n", p1.x, p1.y);

    if(bytes_wrote <= 0){
        printf("Error Writing\n");
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    // --- READ ---
    int elements_read = fscanf(file, "%d, %d\n", &p2.x, &p2.y);
    if(elements_read < 2){
        printf("Error Reading\n");
        fclose(file);
        return 2;
    }

    fclose(file);

    //sscanf(buffer_in, "%d, %d\n", &p2.x, &p2.y);
    printf("Read from file the point: %d %d\n", p2.x, p2.y);
    
    return 0;
}