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
    FILE *file;
    void *buffer1;
    void *buffer2;

    buffer1 = malloc(8);
    *((int *)buffer1) = 1;
    *((void **)buffer1 + 1) = malloc(8);

    buffer2 = malloc(8);
    *((int *)buffer2) = 2;
    *((void **)buffer2 + 1) = malloc(8);

    strcpy(*((char **)buffer1 + 1), argv[1]);
    strcpy(*((char **)buffer2 + 1), argv[2]);

    file = fopen("/home/user/level8/.pass", "r");
    fgets(c, sizeof(c), file);
    fclose(file);
    puts("~~");

    return 0;
}