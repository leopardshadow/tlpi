
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t childPid;

    for(int i = 1; i < 5; i++) {

        switch (fork())
        {
        case -1:
            exit(-1);
        case 0:    // child process
            sleep(i);
            printf("end of child process %d\n", getpid());
            exit(i);
        default:
            break;
        }
    }

    // the results looks strange ..
    // update: fork() = 0 is child, <> 0 is parent owo

    int status;

    for(int i = 1; i < 5; i++) {
        childPid = wait(&status);
        printf("child %d ends with status %d\n", childPid, status >> 8);
    }
    printf("end of parent process\n");

    /*
        when the process is normally terminated,
        status = exitStatus << 8;
        (i.e. higher 8 bit: exitStatus, lower 8 bit: 0)
    */

    return 0;
}
