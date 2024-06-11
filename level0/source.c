#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av){
    char *arg = strdup("/bin/sh");
    if (atoi(av[1]) == 423){
        execv("/bin/sh", &arg);
    }
    return 0;
}