#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("%d\n", getpid());

    printf("process created\n");
    getchar();

    /*
        $ lsof -p  <pid>
    */

    /*
        COMMAND   PID  USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
        a.out   23489 cheng  cwd    DIR    1,4      288         12907367196 /Users/cheng/Desktop/tlpi/ch4
        a.out   23489 cheng  txt    REG    1,4     8520         12907602969 /Users/cheng/Desktop/tlpi/ch4/a.out
        a.out   23489 cheng  txt    REG    1,4  1534352 1162923500311685154 /usr/lib/dyld
        a.out   23489 cheng    0u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    1u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    2u   CHR   16,1  0t33686                2485 /dev/ttys001
    */

    int openFlag = O_WRONLY | O_CREAT;
    mode_t filePerms = S_IRUSR | S_IWUSR;
    int fd = open("holes", openFlag, filePerms);

    printf("file opened\n");
    getchar();

    /*
        COMMAND   PID  USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
        a.out   23489 cheng  cwd    DIR    1,4      288         12907367196 /Users/cheng/Desktop/tlpi/ch4
        a.out   23489 cheng  txt    REG    1,4     8520         12907602969 /Users/cheng/Desktop/tlpi/ch4/a.out
        a.out   23489 cheng  txt    REG    1,4  1534352 1162923500311685154 /usr/lib/dyld
        a.out   23489 cheng    0u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    1u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    2u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    3w   REG    1,4      203         12907600496 /Users/cheng/Desktop/tlpi/ch4/holes
    */

    close(fd);

    printf("file closed\n");
    getchar();

    /*
        COMMAND   PID  USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
        a.out   23489 cheng  cwd    DIR    1,4      288         12907367196 /Users/cheng/Desktop/tlpi/ch4
        a.out   23489 cheng  txt    REG    1,4     8520         12907602969 /Users/cheng/Desktop/tlpi/ch4/a.out
        a.out   23489 cheng  txt    REG    1,4  1534352 1162923500311685154 /usr/lib/dyld
        a.out   23489 cheng    0u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    1u   CHR   16,1  0t33686                2485 /dev/ttys001
        a.out   23489 cheng    2u   CHR   16,1  0t33686                2485 /dev/ttys001

    */


    return 0;
}
