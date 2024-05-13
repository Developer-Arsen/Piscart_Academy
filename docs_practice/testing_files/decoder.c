#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

int main () {
    char * fileName = "./encoded.txt";
    int fd = open(fileName, O_RDWR);

    char c = 0;
    while (read(fd, &c, 1))
    {   
        int index = 0;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char diff = 0;
            if (c == 'a' || c == 'b' || c == 'c') {
                diff = 'c' - c;
                c = 'z' - diff;
            }
            else if (c == 'A' || c == 'B' || c == 'C') {
                diff = 'C' - c;
                c = 'Z' - diff;
            }
            else {
                c = c- 3;
            } 
        }
        lseek(fd, -1, SEEK_CUR);
        write(fd, &c, 1);
    }
}
