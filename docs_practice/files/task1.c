#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

void handleOpen(int fd) {
    if (fd < 0) {
        printf("Error in creating file");
        exit(EXIT_FAILURE);
    }
}

int main () {
    char * fileName = "./file1.txt";
    char * fileName2 = "./file2.txt";
    char msg[1024];

    int fd = open(fileName, O_RDWR);
    handleOpen(fd);

    struct stat info;

    if (stat(fileName, &info)) {
        printf("Error in reading meta Data");
        exit(EXIT_FAILURE);
    }

    int bytesCount = info.st_size;
    int left = info.st_size;
    double copiedCount = 0;

    int fd2 = open(fileName2, O_RDWR | O_CREAT , 0777);
    handleOpen(fd2);

    printf("Started Copying \n");
    while (left)
    {
        int size = read(fd, msg, 1024);
        left -= size;
        copiedCount += size;

        write(fd2, msg, size);
        printf("Processing %f %%", copiedCount / bytesCount * 100);
        printf("\r");
        usleep(100);
    }

    // if (fysnc(fd2) < 1) {
    //     printf("Sync error");
    //     exit(EXIT_FAILURE);
    // }
    
    close(fd);
    close(fd2);
    
    printf("\n Completed \n");

}