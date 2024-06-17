#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclaration de la variable globale c
char c[68];

int m() {
    time_t currentTime;
    currentTime = time(0);
    return printf("%s - %ld\n", c, currentTime);
}

int main(int argc, const char **argv, const char **envp) {
    int *buffer1;
    int *buffer2;
    FILE *file;

    buffer1 = (int *)malloc(8);
    buffer1[0] = 1;
    buffer1[1] = (int)malloc(8);

    buffer2 = (int *)malloc(8);
    buffer2[0] = 2;
    buffer2[1] = (int)malloc(8);

    strcpy((char *)buffer1[1], argv[1]);
    strcpy((char *)buffer2[1], argv[2]);

    file = fopen("/home/user/level8/.pass", "r");
    fgets(c, sizeof(c), file);
    puts("~~");

    return 0;
}