#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    // after the 3 consecutive 8 fork(),
    // in total 8 processed are created
    fork();
    fork();
    fork();
    printf("*\n");
    return 0;
}
