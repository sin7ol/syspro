#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;

    // 파일 생성
    if ((fd1 = creat("myfile", 0600)) == -1) {
        perror("myfile");  // 파일 생성 실패 시 오류 메시지 출력
        exit(1);
    }

    // 파일에 "Hello! Linux" 문자열 쓰기
    write(fd1, "Hello! Linux", 12);

    // 파일 디스크립터 복제
    fd2 = dup(fd1);

    // 복제된 파일 디스크립터를 통해 "Bye! Linux" 문자열 쓰기
    write(fd2, "Bye! Linux", 10);

    // 프로그램 종료
    exit(0);
}


