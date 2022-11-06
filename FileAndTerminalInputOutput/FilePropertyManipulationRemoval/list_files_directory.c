#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

void listFiles(const char* dirname){
    DIR* dir = opendir(dirname);

    if(dir == NULL){
        printf("Failed to list directory with error: %s!\n", strerror(errno));
    }

    printf("Reading files in %s\n", dirname);

    struct dirent* entity;
    entity = readdir(dir);

    while(entity != NULL){
        printf("%hhd %s\n", entity->d_type, entity->d_name);
        if(entity ->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0){
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(dir);
    }

    closedir(dir);  
}

int main(int argc, char* argv[]) {
    listFiles("..");
    return 0;
}