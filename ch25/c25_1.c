#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t childPid;
    int status;

    switch(childPid = fork()) {
        case -1:
            fprintf(stderr, "fork fail");
            exit(-1);
        case 0:
            exit(-1);
            break;
        default:
            childPid = wait(&status);
            printf("pid %d return with status %d\n", childPid, status);
            /*
                exit(-1) -- 65280 (255 * 256)
                exit(0)  -- 0
                exit(1)  -- 256
                exit(2)  -- 512
                exit(3)  -- 768
                exit(4)  -- 1024

                ... Why??
            */
    }

    return 0;
}
