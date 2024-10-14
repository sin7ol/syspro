#include <stdio.h>

/* 파일 복사 프로그램 */
int main(int argc, char *argv[])
{
    char c;
    FILE *fp1, *fp2;

    // 명령줄 인수 검사
    if (argc != 3) {
        fprintf(stderr, "사용법: %s File1 File2\n", argv[0]);
        return 1;
    }

    // 첫 번째 파일 열기 (읽기 모드)
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    // 두 번째 파일 열기 (쓰기 모드)
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[2]);
        fclose(fp1); // 첫 번째 파일 닫기
        return 3;
    }

    // 파일 복사 수행
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    // 파일 닫기
    fclose(fp1);
    fclose(fp2);

    return 0;
}

