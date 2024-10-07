#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 학번을 입력받아 해당 학생의 레코드를 파일에서 읽어 출력한다. */
int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;

    // 입력 파일이 지정되지 않은 경우 사용법 출력
    if (argc < 2) {
        fprintf(stderr, "How to use: %s file\n", argv[0]);
        exit(1);
    }

    // 읽기 전용으로 파일 열기
    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    do {
        // 학번 입력받기
        printf("\nEnter StudentID to search: ");
        if (scanf("%d", &id) == 1) {
            // 해당 학번의 위치로 이동
            lseek(fd, (id - START_ID) * sizeof(record), SEEK_SET);

            // 해당 레코드 읽기
            if (read(fd, (char *)&record, sizeof(record)) > 0 && record.id != 0) {
                printf("Name: %s\t StuID: %d\t Score: %d\n", record.name, record.id, record.score);
            } else {
                printf("Record %d Null\n", id);
            }
        } else {
            printf("Input Error\n");
        }

        // 계속할지 여부 묻기
        printf("Continue? (Y/N) ");
        scanf(" %c", &c);
    } while (c == 'Y');

    close(fd); // 파일 닫기
    exit(0);
}

