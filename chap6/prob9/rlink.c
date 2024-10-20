#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buffer[1024];
    int nread;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <link file>\n", argv[0]);
        exit(1);
    }

    nread = readlink(argv[1], buffer, 1024);
    if (nread > 0) {
        write(1, buffer, nread);
        write(1, "\n", 1);
        exit(0);
    } else {
        fprintf(stderr, "Error: No such link\n");
        exit(1);
    }
}

