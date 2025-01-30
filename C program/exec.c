#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
    printf("Current process is Running with PID %d\n",getpid());
    const char *args[] = {"execExample",NULL};
    execv("./output",args);
    printf("After exec()");
}