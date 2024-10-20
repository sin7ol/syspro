#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

void printStat(char *pathname, char *file, struct stat *st, int show_inode, int show_quote, int show_type);

int main(int argc, char *argv[])
{
    DIR *dp;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];
    char *dir = ".";
    int show_inode = 0, show_quote = 0, show_type = 0;

    // 옵션 처리
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0)
            show_inode = 1;
        else if (strcmp(argv[i], "-Q") == 0)
            show_quote = 1;
        else if (strcmp(argv[i], "-p") == 0)
            show_type = 1;
        else
            dir = argv[i];
    }

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0) {
            perror(path);
            continue;
        }
        printStat(path, d->d_name, &st, show_inode, show_quote, show_type);
    }

    closedir(dp);
    exit(0);
}

void printStat(char *pathname, char *file, struct stat *st, int show_inode, int show_quote, int show_type)
{
    if (show_inode)
        printf("%ld ", st->st_ino);

    if (show_quote)
        printf("\"%s\" ", file);
    else
        printf("%s ", file);

    if (show_type && S_ISDIR(st->st_mode))
        printf("/");

    printf("\n");
}

