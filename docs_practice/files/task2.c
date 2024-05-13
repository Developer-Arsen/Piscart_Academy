#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void handleOpen(int fd) {
    if (fd < 0) {
        printf("Error in creating file");
        exit(EXIT_FAILURE);
    }
}

int main () {
    char * fileName = "./file.txt";
    
    int fd = open(fileName, O_RDWR | O_APPEND);
    pwrite(fd, "msg", 3, 0);
    pwrite(fd, "msg", 3, 0);
    // handleOpen(fd);

    // char buff[1024];
    // int size = read (fd, buff, 1024);

    // char textBuff[1024];
    // puts(buff);

    // scanf("%[^\n]s", textBuff);
    // int scanedSize = strlen(textBuff);
    // write(fd, textBuff, scanedSize);

    close(fd);
}