#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINE 1000
#define MAXINPUT 5

void sort_by_length(char lines[][MAXLINE], int n);

int main() {
    char lines[MAXINPUT][MAXLINE];
    char temp[MAXLINE];
    int i, len;

    for (i = 0; i < MAXINPUT; i++) {
        fgets(lines[i], MAXLINE, stdin);

        len = strlen(lines[i]);
        if (lines[i][len - 1] == '\n') {
            lines[i][len - 1] = '\0';
        }
    }

    sort_by_length(lines, MAXINPUT);

    for (i = 0; i < MAXINPUT; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

void sort_by_length(char lines[][MAXLINE], int n) {
    char temp[MAXLINE];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(lines[i]) < strlen(lines[j])) {
                copy(lines[i], temp);
                copy(lines[j], lines[i]);
                copy(temp, lines[j]);
            }
        }
    }
}

