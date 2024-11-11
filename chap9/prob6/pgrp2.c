#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid, gid;

    // 큰따옴표 수정 및 반환 타입 수정
    printf("PARENT: PID = %d GID = %d\n", getpid(), getpgrp());
    pid = fork();
    if (pid == 0) { // 자식 프로세스
        setpgid(0, 0);
        printf("CHILD: PID = %d GID = %d\n", getpid(), getpgrp());
    }

    return 0;
}

