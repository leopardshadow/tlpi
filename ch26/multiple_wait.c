
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t childPid;

    for(int i = 1; i < 5; i++) {

        switch ((childPid = fork()))
        {
        case -1:
            exit(-1);
        case 0:
            break;
        default:  // child process
            sleep(i);
            printf("end of child process %d\n", childPid);
            exit(i);
            break;
        }
    }

    // the results looks strange ..
    for(int i = 1; i < 5; i++) {
        wait(NULL);
        printf("wait\n");
    }
    printf("end of parent process\n");

    return 0;
}
