#include <stdio.h>
#include <stdlib.h> // exit() 함수를 사용하기 위해 필요

#define MAXLINE 80

/* 텍스트 파일에 줄 번호를 붙여 출력한다. */
int main(int argc, char *argv[])
{
    FILE *fp;
    int line = 0;
    char buffer[MAXLINE];

    // 명령줄 인수 검사
    if (argc != 2) {
        fprintf(stderr, "사용법: %s FileName\n", argv[0]);
        exit(1);
    }

    // 파일 열기
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        exit(2);
    }

    // 파일 내용 읽기 및 줄 번호 출력
    while (fgets(buffer, MAXLINE, fp) != NULL) { // 한 줄 읽기
        line++;
        printf("%3d %s", line, buffer);
    }

    fclose(fp);
    exit(0);
}

