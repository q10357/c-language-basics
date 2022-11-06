#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Reading structs from input.txt

typedef struct Point {
    int x, y;
    int val;
} Point ;

int main(int argc, char* argv[]){
    FILE* file = fopen("input.txt", "r");
    if(file == NULL) {
        printf("Error in reading file");
        return 1;
    }

    char buffer[200];
    fgets(buffer, 200, file);

    Point points[100];
    int i = 0;
    //Condition with tells us if we are at the end of file
    while(!feof(file)){
        Point* p = points + i;
        sscanf(buffer, "%d %d %d", &p->x, &p->y, &p->val);
        fgets(buffer, 200, file);
        i++;
    }

    int n = i;
    for ( i = 0; i < n; i++ ){
        printf("Read point; %d %d %d\n", points[i].x, points[i].y, points[i].val);
    }

    fclose(file);
    printf("\n");

    return 0;
}

/*
fread() vs fscanf()

Both functions are used to read data, basic difference is given below:-

fscanf() - This function is used to read data from a file.

Syntax: fscanf(filepointer,”format specifier”,&v1,&v2,….);

Ex: fscanf(fp,”%d%d%d”,&a,&b,&c);

fread() - this function is used to read data into a structure from a file.

Syntax: fread(&structure varable,size of(struct structurevariable),1,filepointer);

Ex: fread(&s,size of(struct s),1,fp);
*/