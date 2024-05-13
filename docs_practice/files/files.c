#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main() {
    // int fd = open("./file.txt", O_CREAT | O_RDWR, 0777);
    int fd1, fd2;
    char c;
    fd1 = open("file.txt", O_RDONLY, 0);
    fd2 = open("file.txt", O_RDONLY, 0);
    read(fd1, &c, 1);
    read(fd2, &c, 1);
    printf("c = %c\n", c);
    // char str[10];
    // write(fd, "es", 2);
    // fsync(fd);
    
    // lseek(fd, 0, 0);

    // read(fd, str, 10);
    // close(fd);

    // // fd = open("./file.txt", O_CREAT | O_RDWR, 0777);
    // // ssize_t a = read(fd, str, 10);

    // printf(str);
}