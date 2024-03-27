#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

int main () {
    int fd = open("./example.txt", O_CREAT | O_RDWR, 0777);

    char * ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 

    if (ptr  == MAP_FAILED) {
        fprintf(stderr, "error");
        exit(1);
    }

    ptr[0] = 20;
    while(1);

    return 0;
    
}