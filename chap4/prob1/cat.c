#include <stdio.h>

/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    // 파일 열기
    if (argc < 2) {
        fp = stdin; // 명령줄 인수가 없으면 표준입력 사용
    } else {
        fp = fopen(argv[1], "r"); // 읽기 전용으로 파일 열기
        if (fp == NULL) { // 파일 열기에 실패한 경우
            perror("파일 열기 오류");
            return 1;
        }
    }

    // 파일 내용 출력
    while ((c = getc(fp)) != EOF) { // 파일 끝이 아니면
        putc(c, stdout); // 읽은 문자를 표준출력에 출력
    }

    // 파일 닫기
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

