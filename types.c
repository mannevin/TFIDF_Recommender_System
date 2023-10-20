#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
void getType(mode_t fs, char* dirName) {
    if(S_ISREG(fs)) {
        printf("%s: regular file\n", dirName);
    }
    else if(S_ISDIR(fs)) {
        printf("%s: directory\n", dirName);
    }
    else if(S_ISCHR(fs)) {
        printf("%s: character device\n", dirName);
    }
    else if(S_ISREG(fs)) {
        printf("%s: regular file\n", dirName);
    }
    else if(S_ISBLK(fs)) {
        printf("%s: block device\n", dirName);
    }
    else if(S_ISFIFO(fs)) {
        printf("%s: fifo\n", dirName);
    }
    else if(S_ISLNK(fs)) {
        printf("%s: symbolic link\n", dirName);
    }
    else if(S_ISSOCK(fs)) {
        printf("%s: socket\n", dirName);
    }
}
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("./types path1 [path2 ...]\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++) {
        char* dirName = argv[1];
        struct stat filestats;
        int st;
        if ((st = stat(dirName, &filestats)) != -1) {
            getType(filestats.st_mode, dirName);
        } else {
            printf("%s: path error\n", dirName);
        }
    }
}
