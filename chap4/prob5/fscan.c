#include <stdio.h>
#include <stdlib.h> // exit() 함수를 사용하기 위해 필요
#include "student.h"

/* 텍스트 파일에서 학생 정보를 읽어 프린트한다. */
int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp;

    // 명령줄 인수 검사
    if (argc != 2) {
        fprintf(stderr, "사용법: %s FileName\n", argv[0]);
        return 1;
    }

    // 파일 열기
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    // 파일 내용 출력
    printf("%-9s %-7s %-4s\n", "StudentID", "Name", "Score");
    while (fscanf(fp, "%d %s %hd", &rec.id, rec.name, &rec.score) == 3) {
        printf("%-9d %-7s %-4d\n", rec.id, rec.name, rec.score);
    }

    // 파일 닫기
    fclose(fp);
    return 0;
}

