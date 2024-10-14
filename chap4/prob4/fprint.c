#include <stdio.h>
#include <stdlib.h> // exit() 함수를 사용하기 위해 필요
#include "student.h"

/* 학생 정보를 읽어 텍스트 파일에 저장한다. */
int main(int argc, char* argv[])
{
    struct student rec;
    FILE *fp;

    // 명령줄 인수 검사
    if (argc != 2) {
        fprintf(stderr, "사용법: %s FileName\n", argv[0]);
        return 1;
    }

    // 파일 열기
    if ((fp = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    // 학생 정보 입력 안내 출력
    printf("%-9s %-7s %-4s\n", "StudentID", "Name", "Score");

    // 학생 정보 입력 및 저장
    while (scanf("%d %s %hd", &rec.id, rec.name, &rec.score) == 3) {
        if (rec.id <= 0 || rec.score < 0) {
            fprintf(stderr, "잘못된 입력입니다. 양수를 입력하세요.\n");
            continue;
        }
        fprintf(fp, "%d %s %d\n", rec.id, rec.name, rec.score);
        printf("학생 정보를 추가로 입력하세요 (종료하려면 Ctrl+D):\n");
    }

    // 파일 닫기
    fclose(fp);
    return 0;
}

