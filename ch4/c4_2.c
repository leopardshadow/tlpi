#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 1000

int main(int argc, char const *argv[])
{
    if(argc != 3) {
        fprintf(stderr, "wrong arguments number\r\n");
    }

    int fdRead = open(argv[1], O_RDONLY);
    int fdWrite = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if(fdRead == -1) {
        fprintf(stderr, "fail to open file %s\r\n", argv[1]);
        _exit(-1);
    }

    if(fdWrite == -1) {
        fprintf(stderr, "fail to open file %s\r\n", argv[2]);
        _exit(-1);
    }


    char buf[BUF_SIZE];
    int numRead;

    while((numRead = read(fdRead, buf, BUF_SIZE)) > 0) {
        write(fdWrite, buf, numRead);
    }

    close(fdRead);
    close(fdWrite);

    return 0;
}
