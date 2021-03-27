#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    // errno is defined somewhere else
    errno = 0;

    int fd = open("a_file_doesn't_exist", O_RDONLY);

    // since the file doesn't exist, file descriptor will retuen -1
    printf("%d\n", fd);

    // however, there might be many possibilities for fd = -1
    // print the errno value
    printf("%d\n", errno);
    fprintf( stderr, "system error: %s\n" , sys_errlist[errno] ); 

    return 0;
}
