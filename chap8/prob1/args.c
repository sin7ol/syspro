#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++)  // 모든 명령줄 인수를 출력
        printf("argv[%d]: %s\n", i, argv[i]);

    exit(0);
}

