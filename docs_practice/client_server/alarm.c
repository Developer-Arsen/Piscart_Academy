#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include <stdlib.h>

void handle_alarm (int signum) {
    system("spd-say \"Barlus dzez\"");
}

void checkValidity (int n);
void scanNumber(int * n);
void setAlarm(int n);
void addAlarmHandler();

int main () {
    addAlarmHandler();

    int n = 0;
    scanNumber(&n);
    setAlarm(n);

    n = 0;
    do {
        int answer = 0;
        printf("Do you want to set timer again ? \n 1: yes \n 0: no \n");
        scanf("%d", &answer);

        if (!answer) break;

        scanNumber(&n);
        setAlarm(n);
    } while(1);

    printf("alarm end");
}


void checkValidity (int n) {
    if (!n) {
        printf("not Valid number \n");
        exit(EXIT_FAILURE);
    }
}

void scanNumber(int * n) {
    printf("Please etner alarm time \n");
    scanf("%d", &(*n));
    checkValidity(*n);
}

void setAlarm(int n) {
    alarm(n);
    printf("Timer started \n");
    pause();
}

void addAlarmHandler() {
    if (signal(SIGALRM, handle_alarm) == SIG_ERR) {
        printf("Something went wrong");
        exit(EXIT_FAILURE);
    }
}