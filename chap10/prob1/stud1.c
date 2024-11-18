#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
};

/* 입력받을 학생 수를 미리 입력받고 이어서 학생 정보를 입력받은 후,
이들 학생 정보를 역순으로 출력하는 프로그램 */

int main() {
    struct student *ptr; // 동적 할당된 블록을 가리킬 포인터
    int n, i;

    printf("몇 명의 학생을 입력하겠습니까? ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "오류: 학생 수를 잘못 입력했습니다.\n");
        fprintf(stderr, "프로그램을 종료합니다.\n");
        exit(1);
    }

    ptr = (struct student *) malloc(n * sizeof(struct student));
    if (ptr == NULL) {
        perror("malloc");
        exit(2);
    }

    printf("%d 명의 학번과 이름을 입력하세요.\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d %s", &ptr[i].id, ptr[i].name);
    }

    printf("\n* 학생 정보(역순) *\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d %s\n", ptr[i].id, ptr[i].name);
    }
    
    free(ptr); // 동적 할당 해제
    return 0;
}

