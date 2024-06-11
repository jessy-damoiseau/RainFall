#include <stdlib.h>

int main(int ac, char **av){
    if (atoi(av[1]) == 423){
        system("/bin/sh");
    }
    return 0;
}