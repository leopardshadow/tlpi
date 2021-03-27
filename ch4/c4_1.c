#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define N 2

int main(int argc, char const *argv[])
{
    char buf[N];
    ssize_t rdNum;
    mode_t filePerms = S_IRUSR | S_IWUSR;

    char c = getopt(argc, argv, "a");
    if(c=='a') 
        printf("OAOAOA");
    int openFlag = O_WRONLY | O_CREAT | O_TRUNC;

    int fd = open(argv[1], openFlag, filePerms);
    // printf("%d\n", fd);
    if(fd == -1) {
        _exit(-1);
    }

    for(;;) {
        rdNum = read(STDIN_FILENO, buf, N);
        // printf(" rd = %zu ", rdNum);

        if(rdNum == -1)
            _exit(-1);
        
        write(fd, buf, rdNum);
        write(STDOUT_FILENO, buf, rdNum);

        if(buf[rdNum-1]=='\n')
            break;
    }

    close(fd);

    return 0;
}
