#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int *shared_memory = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        munmap(shared_memory, sizeof(int));
        return EXIT_FAILURE;
    }
    if (pid == 0) {
        sleep(1);
        printf("Child reads: %d\n", *shared_memory);
        munmap(shared_memory, sizeof(int));
        exit(EXIT_SUCCESS);
    } else {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i;
        }
        *shared_memory = sum;
        wait(NULL);
        munmap(shared_memory, sizeof(int));
        printf("Child reads: %d\n", *shared_memory);
    }

    

    return EXIT_SUCCESS;
}