#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <stdlib.h>

int ind = 0;
char c = '\0';

void user1_handler(int signum) {
    ind++;
}

void user2_handler(int signum) {
    c = c | 1 << ind;
    ind++;
}

void userterm_handler(int signum) {
    ind = 0;
    printf("%c", c);
    c = 0;
    fflush(stdout);
}

void addUserSignalHandlers() {
    if (signal(SIGUSR1, user1_handler) == SIG_ERR) {
        printf("lav eli de");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR2, user2_handler) == SIG_ERR) {
        printf("lav eli de");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGALRM, userterm_handler) == SIG_ERR) {
        printf("lav eli de");
        exit(EXIT_FAILURE);
    }
}

int main () {
    addUserSignalHandlers();
    pid_t pid = getpid();
    printf("%d \n", pid);
    
    while (1);
        
}