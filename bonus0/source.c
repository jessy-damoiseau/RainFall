#include <stdio.h>
#include <string.h>
#include <unistd.h>

void p(char *str1, char *str2) {
    char buffer[4120];
    puts(str2);
    read(0, buffer, 4096);
    char *newline = strchr(buffer, '\n');
    *newline = '\0';
    strncpy(str1, buffer, 20);
}

void pp(char *str1) {
    char buffer1[80];
    char buffer2[80];
    p(buffer1, " - ");
    p(buffer2, " - ");
    strcpy(str1, buffer1);
    str1[strlen(str1)] = ' ';
    strcat(str1, buffer2);
}

int main() {
    char str1[64];
    pp(str1);
    puts(str1);
    return 0;
}