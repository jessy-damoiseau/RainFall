#include <stdio.h>
#include <string.h>

int m;

void v(){

    char s[520];
    int result;

    fgets(s, 512, stdin);
    printf(s);
    if (m == 64){
        fwrite("Wait what?!\n", 1u, 0xCu, stdout);
        system("/bin/sh");
    }
    return;
}

int main(){
    v();
    return 0;
}