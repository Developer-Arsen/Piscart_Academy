#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    __pid_t pid = 0;
    for (size_t i = 0; i < n; i++)
    {
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
    }
    
    return 0;
}
