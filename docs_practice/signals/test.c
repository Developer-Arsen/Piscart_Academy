#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void singal_handler(int signum) {
   write(1, "msg", 4);
}

int main () {
    signal(SIGSEGV, singal_handler);
    int arr [200000000000000];
    printf("error is %s", strerror(errno));

    return EXIT_SUCCESS;

}