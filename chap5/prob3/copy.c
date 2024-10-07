#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/* 파일 복사 프로그램 */
int main(int argc, char *argv[])
{
    int fd1, fd2, n;
    char buf[BUFSIZ];

    // 입력 인수 개수가 3개가 아닌 경우 사용법 출력 후 종료
    if (argc != 3) {
        fprintf(stderr, "How to use: %s file1 file2\n", argv[0]);
        exit(1);
    }

    // 원본 파일 읽기 전용으로 열기
    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    // 새로 생성할 파일을 쓰기 전용으로 열기 (없으면 생성, 기존 내용은 삭제)
    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror(argv[2]);
        exit(3);
    }

    // 원본 파일을 읽고 대상 파일에 쓰기
    while ((n = read(fd1, buf, BUFSIZ)) > 0) {
        if (write(fd2, buf, n) != n) {
            perror("write error");
            exit(4);
        }
    }

    if (n == -1) {
        perror("read error");
        exit(5);
    }

    // 파일 닫기
    close(fd1);
    close(fd2);

    exit(0);
}

