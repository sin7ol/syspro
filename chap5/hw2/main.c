#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main() {
    FILE *file;
    char savedText[MAX_LINES][MAX_LENGTH];
    int totalLines = 0;

    file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("File open error");
        return 1;
    }

    while (fgets(savedText[totalLines], MAX_LENGTH, file) != NULL) {
        totalLines++;
    }
    fclose(file);

    for (int i = totalLines - 1; i >= 0; i--) {
        printf("%s", savedText[i]);
    }

    return 0;
}

