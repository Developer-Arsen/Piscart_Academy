#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    __pid_t pid = 0;

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("I am child %d \n", pid);
    } else {
        printf("I am parent %d \n", pid);
    }
    return 0;
}
