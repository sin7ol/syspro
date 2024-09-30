#include <stdio.h>
#include <string.h> // strlen, strcpy 함수 포함
#define MAXLINE 1000 // 적절한 버퍼 크기 지정

char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄

int main() {
    int len;
    int max = 0;

    while (fgets(line, MAXLINE, stdin) != NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';  // 개행 문자 제거
            len--;
        }
        if (len > max) {
            max = len;
            strcpy(longest, line); // copy() 대신 strcpy() 사용
        }
    }
    
    if (max > 0) { // 입력 줄이 있었다면
        printf("%s\n", longest);
    }
    
    return 0;
}

