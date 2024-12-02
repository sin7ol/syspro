#include <stdio.h>
#include <stdlib.h>    
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>      

#define MAXLINE 100

/* 이름 있는 파이프를 통해 읽은 내용을 프린트한다. */
int readLine(int fd, char *str);  // 함수 선언 추가

int main()
{
    int fd;
    char str[MAXLINE];
    
    unlink("myPipe");
    mkfifo("myPipe", 0660);
    

    fd = open("myPipe", O_RDONLY);
    if (fd == -1) {
        perror("open 오류");        return 1;
    }

    while (readLine(fd, str)) {
        printf("%s\n", str);
    }

    close(fd);
    return 0;
}

int readLine(int fd, char *str)
{
    int n;
    do {
        n = read(fd, str, 1);
    } while (n > 0 && *str++ != '\0');
    return (n > 0);
}

