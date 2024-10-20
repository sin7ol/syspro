#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    int line_number = 1;
    int show_line_numbers = 0;
    int i = 1;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        show_line_numbers = 1;
        i = 2; 
    }

    if (argc < 2 || (show_line_numbers && argc == 2)) {
        fp = stdin;
        if (show_line_numbers) {
            printf("%6d  ", line_number++);
        }
        while ((c = getc(fp)) != EOF) {
            putc(c, stdout);
            if (show_line_numbers && c == '\n') {
                printf("%6d  ", line_number++);
            }
        }
    } else {
        
		for (; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                perror("Error opening file");
                return 1;
            }
            if (show_line_numbers) {
                printf("%6d  ", line_number++);
            }
            while ((c = getc(fp)) != EOF) {
                putc(c, stdout);
                if (show_line_numbers && c == '\n') {
                    printf("%6d  ", line_number++);
                }
            }
            fclose(fp);
        }
    }

    return 0;
}


