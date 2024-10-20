#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <original file> <link name>\n", argv[0]);
        exit(1);
    }

    if (link(argv[1], argv[2]) == -1) {
        perror("link");
        exit(1);
    }
    exit(0);
}

