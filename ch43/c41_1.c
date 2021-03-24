#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 10000
#define N        1

int main(int argc, char const *argv[])
{
    int filedes[2];
    char buf[BUF_SIZE];
    ssize_t numRead;

    for(int i=0; i<BUF_SIZE; i++) {
        buf[i] = 'a';
    }

    if(pipe(filedes) == -1) {
        exit(-1);
    }

    switch (fork())
    {
    case -1:
        exit(-1);
        break;

    case 0: // child (write)
        if(close(filedes[0] == -1))
            exit(-1);

        for(int i=0; i<N; i++)
            write(filedes[1], buf, BUF_SIZE);

        close(filedes[1]);

        // wait(NULL);

        break;

    default: // parent (read)
        if(close(filedes[1] == -1))
            exit(-1);

        for(;;) {
            numRead = read(filedes[0], buf, BUF_SIZE-3);
            printf("%zd\n", numRead);

            if(numRead == -1)
                exit(-1);
            if(numRead == 0)
                break;
        }
        
        printf("%d chars passed through pipe\n", BUF_SIZE*N);

        break;
    }

    return 0;
}

