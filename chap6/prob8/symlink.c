#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <target> <link name>\n", argv[0]);
        exit(1);
    }

    if (symlink(argv[1], argv[2]) == -1) {
        perror("symlink");
        exit(1);
    }
    exit(0);
}

