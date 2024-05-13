#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int sum = 0;

int main() {

    pid_t pid = 0;
    pid = fork();
    if (pid == 0) {
        sum = 10;
        while (sum != 20);
        printf("aaaa");
        exit(EXIT_SUCCESS);
    } else if (pid > 0) {
        pid_t tmp1 = fork();

        if (tmp1 == 0) {
            sum += 10;
            printf("%d", sum);
            // while (sum != 20);
            exit(EXIT_SUCCESS);
        } else if (tmp1 > 0) {
            wait(NULL);
            printf("I am parent \n");
        }
    }

    return 0;
}

