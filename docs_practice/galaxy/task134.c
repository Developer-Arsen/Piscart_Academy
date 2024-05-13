#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    __pid_t pid = 0;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("I am child %d \n", getpid());
        exit(EXIT_SUCCESS);
    }
    else {
        wait(NULL);
    }
    return 0;
}
