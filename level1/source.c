#include <stdio.h>
#include <stdlib.h>

void run(){
    fwrite("Good... Wait what?\n",1,0x13, stdout);
    system("/bin/sh");
    return;
}

int main(){
    char s[76];
    return (int)gets(s);
}