#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid1, pid2, count1 = 0, count2 = 0;

    pid1 = fork();
    if (pid1 == 0) {
        while (1) {
            sleep(1);
            printf("child [1] execute: %d\n", ++count1);
        }
    }

    pid2 = fork();
    if (pid2 == 0) {
        while (1) {
            sleep(1);
            printf("child [2] execute: %d\n", ++count2);
        }
    }

    while (1) {
        sleep(1);
    }

    return 0;
}

