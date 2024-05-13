#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void printBeforeKill() {
    printf("byeee");
}

void test2() {
    printf("dont forget me \n");
}

int main() {
    atexit(printBeforeKill);
    atexit(test2);
    
    return 0;
}

