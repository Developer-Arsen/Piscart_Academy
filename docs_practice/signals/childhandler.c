#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Caught SIGINT signal (Ctrl+C)\n");
    signal(SIGINT, SIG_DFL);
}
void sigterm_handler(int signum) {
    printf("Caught SIGTERM signal\n");
}
void sigusr1_handler(int signum) {
    printf("Caught SIGUSR1 signal\n");
}
void sigusr2_handler(int signum) {
    printf("Caught SIGUSR2 signal\n");
}
int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR ||
        signal(SIGTERM, sigterm_handler) == SIG_ERR ||
        signal(SIGUSR1, sigusr1_handler) == SIG_ERR ||
        signal(SIGUSR2, sigusr2_handler) == SIG_ERR ) {
        perror("signal");
        return EXIT_FAILURE;
    }

    __pid_t pid = 0;

    pid = fork();
    if (pid == 0) {
        printf("I am parent \n");
    } else {
        printf("I am child \n");
    }

    while (1) { }
    return EXIT_SUCCESS;
}