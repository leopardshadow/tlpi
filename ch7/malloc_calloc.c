#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 10;

    char* str1 = (char*)malloc(sizeof(char)*n);
    for(int i = 0; i < n; i++) {
        printf("%3d ", (int)(str1[i]));
    }
    printf("\n");
    free(str1);

    char* str2 = (char*)calloc(n, sizeof(char));
    for(int i = 0; i < n; i++) {
        printf("%3d ", (int)(str2[i]));
    }
    printf("\n");
    free(str2);

    return 0;
}
