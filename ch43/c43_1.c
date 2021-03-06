#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const ssize_t BUF_SIZE = 1E7;
const ssize_t N        = 1E10;

// char buf[BUF_SIZE];  // --> NO segmentation fault

int main(int argc, char const *argv[])
{
    int filedes[2];
    char* buf = (char*)malloc(sizeof(char)*BUF_SIZE);  // --> NO segmentation fault
    // char buf[BUF_SIZE];  // ---> segmentation fault
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
            numRead = read(filedes[0], buf, BUF_SIZE);

            if(numRead == -1)
                exit(-1);
            if(numRead == 0)
                close(filedes[0]);
                break;
        }
        
        printf("%zu chars passed through pipe\n", BUF_SIZE*N);

        break;
    }

    return 0;
}