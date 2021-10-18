/*
    when the pipe is full, the process is blocked there
    needs someone to read from the pipe to consume the data
    then it will start to continue
*/


#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, char const *argv[])
{
    int pfd[2];
    char buf[BUF_SIZE];

    if(pipe(pfd) == -1)
        _exit(-1);

    // this child process writes to the pipe and makes it full
    switch (fork())
    {
    case -1:
        _exit(-1);
    case 0:
        printf("start of the producer\n\n");
        close(pfd[0]);
        // ** compare the number with a smaller one **
        //                  1E6
        for(int i = 0; i< 1000000; i++) {
            write(pfd[1], ".", 1);
        }
        close(pfd[1]);
        printf("end of the producer\n\n");
        _exit(0);
    default:  // parent
        break;
    }

    sleep(3);

    switch (fork())
    {
    case -1:
        _exit(-1);
    case 0:
        printf("start of the consumer\n\n");
        close(pfd[1]);
        while (read(pfd[0], buf, BUF_SIZE) > 0)
        {
        }
        printf("afrer reading\n\n");
        close(pfd[0]);
        printf("end of the consumer\n\n");
        _exit(0);
    default:  // parent
        break;
    }

    close(pfd[0]);
    close(pfd[1]);

    wait(NULL);

    return 0;
}
