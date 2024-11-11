#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("부모 프로세스 시작\n");

    if (fork() == 0) {
        // 자식 프로세스는 부모가 끝난 후에 출력을 합니다.
        sleep(1);  // 부모가 종료되기 전에 출력되지 않도록 지연을 줍니다.
        execl("/bin/echo", "echo", "hello", NULL);
        fprintf(stderr, "첫 번째 실패\n");
        exit(1);
    }

    printf("부모 프로세스 끝\n");

    return 0;
}

