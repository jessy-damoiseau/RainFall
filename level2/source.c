#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void p() {
    char buffer[76];
    unsigned int retaddr;

    fflush(stdout);
    gets(buffer);
    if ((retaddr & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", retaddr);
        _exit(1);
    }
    puts(buffer);
    strdup(buffer);
}

int main() {
    p();
    return 0;
}