#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int openFlag = O_WRONLY | O_CREAT;
    mode_t filePerms = S_IRUSR | S_IWUSR;
    int fd = open("holes", openFlag, filePerms);
    if(fd == -1) {
        _exit(-1);
    }

    write(fd, "A", 1);
    lseek(fd, 100, SEEK_CUR);

    write(fd, "B", 1);
    lseek(fd, 100, SEEK_CUR);

    write(fd, "C", 1);
    lseek(fd, 100, SEEK_CUR);

    /*
        after these operations are done,
        "holes" is a file with size 203B (shown by `ls -lha`)
        but actually, only 3 characters are written
    */

    close(fd);

    return 0;
}
