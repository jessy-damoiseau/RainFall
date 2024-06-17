#include <stdlib.h>
#include <string.h>


void n(){
    system("/bin/cat /home/user/level7/.pass");
    return;
}

void m(){
    puts("Nope");
    return;
}

int main(int ac, char **av){
    int (**v4)(void);
    char *v5;

    v5 = (char *)malloc(64);
    v4 = (int (**)(void))malloc(4);
    *v4 = m;
    strcpy(v5, av[1]);
    (*v4)();
    return 0;
}
