#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main() {
    FILE *file;
    char savedText[MAX_LINES][MAX_LENGTH];
    char input[20];
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

    printf("You can choose 1 ~ %d Line\n", totalLines);
    printf("Please enter the line to select: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < totalLines; i++) {
            printf("%d: %s", i + 1, savedText[i]);
        }
    } else {
        int lineNumber = atoi(input);
        if (lineNumber >= 1 && lineNumber <= totalLines) {
            printf("%d: %s", lineNumber, savedText[lineNumber - 1]);
        } else {
            printf("Invalid line number\n");
        }
    }

    return 0;
}

