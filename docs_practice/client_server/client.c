#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <stdlib.h>

int pidNumber = 0;
int count = 0;

int main (int argc, char* argv[]) {
    if (argc < 2) {
        printf("not included pid");
        exit(EXIT_FAILURE);
    }

    pidNumber = atoi(argv[1]);
    char msg[100];

    printf("please enter your meesage \n");
    scanf("%[^\n]s", msg);

    int index = 0;
    while (msg[index] != '\0')
    {
        int n = msg[index++];
        while (n)
        {
            if (n & 1) {
                kill(pidNumber, SIGUSR2);
            } else {
                kill(pidNumber, SIGUSR1);
            }
            usleep(700);
            n /= 2; 
        }
        kill(pidNumber, SIGALRM);
    }
}