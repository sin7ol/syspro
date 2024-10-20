#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <link file>\n", argv[0]);
        exit(1);
    }

    if (unlink(argv[1]) == -1) {
        perror(argv[1]);
        exit(1);
    }
    exit(0);
}

