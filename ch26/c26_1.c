#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t parentPid = -1;
    switch(fork()) {
        case -1:
            exit(-1);
            break;
        case 0: // child
            while((parentPid = getppid()) != 1) {
                sleep(1);
                printf("parentPid = %d\n", parentPid);
            }
            printf("parentPid = %d\n", getppid());
            break;
        default: // parent
            sleep(5);
            _exit(-1);  // Note. the difference between _exit() and exit()
    }
    return 0;
}
