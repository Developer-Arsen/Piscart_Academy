#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main () {
    int fd = open("./file.txt", O_RDONLY | O_RDWR );
    // int fd2 = open("./file.txt", O_RDONLY | O_RDWR | O_APPEND);

    int fd2 = creat("./file.txt", 0644);
    int status =  fcntl(fd2, F_SETFL, O_APPEND);

    write(fd, " start ", 7);
    write(fd2, " end ", 5);

    char msg[10];   
    read(fd2, msg, 10);

    puts(msg);
}