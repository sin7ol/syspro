#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[]) {
    int fd, id;
    char c;
    struct student record;

    // 파일 이름 입력 확인
    if (argc < 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        exit(1);
    }

    // 파일 열기 (읽기/쓰기 모드)
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    // do-while 루프를 사용해 학번 검색 및 수정
    do {
        printf("수정할 학번 입력: ");
        if (scanf("%d", &id) == 1) {
            // 레코드 파일에서 학번 위치 찾기
            lseek(fd, (long)(id - START_ID) * sizeof(record), SEEK_SET);

            // 레코드 읽기
            if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0)) {
                // 학번, 이름, 점수 출력
                printf("학번: %d\t 이름: %s\t 점수: %d\n", record.id, record.name, record.score);

                // 새로운 점수 입력받기
                printf("새로운 점수 입력: ");
                scanf("%d", &record.score);

                // 수정된 레코드 쓰기
                lseek(fd, (long)-sizeof(record), SEEK_CUR);
                write(fd, (char *)&record, sizeof(record));
            } else {
                // 해당 학번의 레코드가 없을 때
                printf("레코드 %d 없음\n", id);
            }
        } else {
            // 입력 오류 처리
            printf("입력 오류\n");
        }

        // 계속할 것인지 묻기
        printf("계속하시겠습니까?(Y/N) ");
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');

    close(fd);
    exit(0);
}

