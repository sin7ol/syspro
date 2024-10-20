#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *src, *dest;
    char buffer[BUFSIZ];
    size_t n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file dest_file\n", argv[0]);
        return 1;
    }

    if ((src = fopen(argv[1], "r")) == NULL) {
        perror("Error opening source file");
        return 2;
    }

    if ((dest = fopen(argv[2], "a")) == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 3;
    }

     while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

  
    fclose(src);
    fclose(dest);

    return 0;
}


