#include <stdio.h>
#include <string.h>

int m;

void p(char *str){
    printf(str);
    return;
}

void v(){
    char str[520];
    fgets(str, 512, stdin);
    p(str);
    if (m == 16930116){
        system("/bin/cat /home/user/level5/.pass");
    }
    return;
}

int main(){
    v();
    return 0;
}