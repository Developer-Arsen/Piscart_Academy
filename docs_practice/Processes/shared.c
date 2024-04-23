#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main () {
    __pid_t pid = 0;
    
    char * ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (ptr  == MAP_FAILED) {
        fprintf(stderr, "error");
        exit(1);
    }
    pid = fork();

    printf("%d \n", pid);

    // if (pid < 0) {
    //     puts("error");
    // } else if (pid == 0) {
    //     while (!ptr[0]);
        
    //     ptr[0] = ptr[0] * ptr[0];
    //     exit(1);
    // } else if (pid > 1) {
    //     ptr[0] = 5;
    //     wait(NULL);
    //     printf("%d", ptr[0]);
    // }
    return 0;
}