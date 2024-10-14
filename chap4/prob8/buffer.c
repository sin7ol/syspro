#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _IO_UNBUFFERED 0x0002
#define _IO_LINE_BUF 0x0200

int main(int argc, char *argv[]) {
    FILE *fp;

    // 명령줄 인수 확인
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일 이름>\n", argv[0]);
        exit(1);
    }

    // stdin, stdout, stderr일 경우 처리
    if (!strcmp(argv[1], "stdin")) {
        fp = stdin;
    } else if (!strcmp(argv[1], "stdout")) {
        fp = stdout;
    } else if (!strcmp(argv[1], "stderr")) {
        fp = stderr;
    } else if ((fp = fopen(argv[1], "r")) == NULL) { // 파일 열기
        perror("파일 열기 오류");
        exit(2);
    }

    printf("Stream = %s, ", argv[1]);

    // 버퍼링 방식 확인
    if (fp->_flags & _IO_UNBUFFERED) {
        printf("Unbuffered");
    } else if (fp->_flags & _IO_LINE_BUF) {
        printf("Line buffered");
    } else {
        printf("Fully buffered");
    }

    printf(", Buffer size = %ld\n", fp->_IO_buf_end - fp->_IO_buf_base);

    // 파일 포인터가 파일인 경우 닫기
    if (fp != stdin && fp != stdout && fp != stderr) {
        fclose(fp);
    }

    return 0;
}

