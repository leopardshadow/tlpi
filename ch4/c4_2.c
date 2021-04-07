#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 100000

int main(int argc, char const *argv[])
{
    int openFlag = O_RDONLY ;
    int fd = open("holes", openFlag);
    if(fd == -1) {
        _exit(-1);
    }

    char buf[BUF_SIZE];

    printf("%lu", read(fd, buf, BUF_SIZE));

    close(fd);

    return 0;
}
