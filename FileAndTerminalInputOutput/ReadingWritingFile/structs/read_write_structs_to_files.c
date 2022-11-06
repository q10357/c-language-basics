#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Serialization
Taking something that is in memory, here struct, saving it to a file
in a certain format, and using the same format to read the same data
and put it BACK in a variable
*/

//JSON FORMAT STRINGS
const char* PERSON_FORMAT_OUT = "{\n\t\"name\": \"%s\", \n\t\"age\": %d, \n\t\"gender\": \"%c\"\n}\n";

//Read all characters until '"'
const char* PERSON_FORMAT_IN = "{\n\t\"name\": \"%[^\"]\", \n\t\"age\": %d, \n\t\"gender\": \"%c\"\n}";

typedef struct Person {
    char name[20];
    int age;
    char gender;
} Person;

int main(int argc, char* argv[]){
    Person p1 = {
        .name = "Isabel",
        .age = 24,
        .gender = 'F'
    };
    Person p2;

    //Save person to file

    FILE *f;

    //w+ says open file, and let me read and write from/to it
    f = fopen("people.dat", "w+");
    if(f == NULL){
        return 1;
    }

    fprintf(f, PERSON_FORMAT_OUT, p1.name, p1.age, p1.gender);
    
    //Setting cursor it at the beginning
    fseek(f, 0, SEEK_SET);
    fscanf(f, PERSON_FORMAT_IN, p2.name, &p2.age, &p2.gender);
    fclose(f);

    printf(PERSON_FORMAT_OUT, p2.name, p2.age, p2.gender);


    return 0;
}
