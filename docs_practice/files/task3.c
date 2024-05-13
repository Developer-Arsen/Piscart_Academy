#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


void handleOpen(int fd) {
    if (fd < 0) {
        printf("Error in creating file");
        exit(EXIT_FAILURE);
    }
}

int main (int argc, char* argv[]) {
    if (argc < 2) exit(EXIT_FAILURE);

    int fd = open(argv[1], O_RDONLY);
    handleOpen(fd);

    struct stat info;
    if (stat(argv[1], &info)) {
        printf("Eror metadata");
        exit(EXIT_FAILURE);
    }

    char buff[100];
    int counts[127] = {}; 

    int size = read(fd, buff, 100); 
    int length = strlen(buff);
    
    for (size_t i = 0; i < length; i++)
    {
        counts[buff[i]] += 1;    
    }

    for (int i = 0; i < 127; i++)
    {
        if (counts[i] > 0) {
            printf("character is %c and count is %d \n", i, counts[i]);
        }
    }
    
    
}