/*
    DO NOT execute it
*/

#include <unistd.h>

int main(int argc, char const *argv[])
{
    for(;;)
        fork();
    return 0;
}
