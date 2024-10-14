#include <stdio.h>
#include <stdlib.h> // exit() 함수를 사용하기 위해 필요
#include "student.h"

/* 파일에 저장된 모든 학생 정보를 읽어서 출력한다. */
int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp;

    // 명령줄 인수 검사
    if (argc != 2) {
        fprintf(stderr, "사용법: %s FileName\n", argv[0]);
        exit(1);
    }

    // 파일 열기
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        exit(2);
    }

    // 파일 내용 출력
    printf("------------------------------------\n");
    printf("%10s %10s %10s\n", "StudentID", "Name", "Score");
    printf("------------------------------------\n");

    // 파일에서 학생 정보 읽어오기
    while (fread(&rec, sizeof(rec), 1, fp) > 0) {
        if (rec.id != 0) {
            printf("%10d %10s %10d\n", rec.id, rec.name, rec.score);
        }
    }

    printf("------------------------------------\n");

    // 파일 닫기
    fclose(fp);
    return 0;
}

