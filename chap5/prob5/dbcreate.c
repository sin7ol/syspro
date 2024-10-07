#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 학생 정보를 입력받아 데이터베이스 파일에 저장한다. */
int main(int argc, char *argv[])
{
    int fd;
    struct student record;

    // 입력 파일이 2개 미만인 경우 사용법 출력
    if (argc < 2) {
        fprintf(stderr, "How to use: %s file\n", argv[0]);
        exit(1);
    }

    // 파일 생성 및 열기 (쓰기 전용, 파일이 없으면 생성, 기존 파일이 있으면 오류)
    if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    // 사용자에게 학번, 이름, 점수를 입력받아 파일에 기록
    printf("%-9s %-8s %-4s\n", "StuID", "Name", "Score");
    while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3) {
        lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET); // 레코드 위치로 이동
        write(fd, (char *) &record, sizeof(record));                 // 레코드 기록
    }

    close(fd); // 파일 닫기
    exit(0);
}

