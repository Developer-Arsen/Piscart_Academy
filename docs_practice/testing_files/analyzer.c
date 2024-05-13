#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

// void check (char words[][1000], int *count, int * wordCounts, const char singleWord) {

//     int setFlag = 1;
//     for (size_t i = 0; i < *count; i++)
//     {
//         if (strcmp(words[i], singleWord) == 0) {
//             setFlag = 0;
//             wordCounts[i]++;
//             break;
//         }
//     }

//     if (setFlag) {
//         strcpy(words[count], singleWord);
//         wordCounts[*count] = 1;
//         count++;
//     }
// }

int main () {
    char * fileName = "./filec.txt";

    int fd = open(fileName, O_RDONLY);
    char words [1000][1000];
    int wordsCounts[1000];

    struct stat info;
    if (stat(fileName, &info) < 0) {
        printf("errror from stat");
        exit(EXIT_FAILURE);
    }

    int bufSize = 1024;
    char buff[bufSize];
    
    int leftToRead = info.st_size;

    int length = 0;
    int count = 0;
    int symbolCounts = 0; 

    while (leftToRead)
    {   
        int sizeReaded = read(fd, buff, bufSize);
        if (sizeReaded == 0 ) break;

        leftToRead -= sizeReaded;
        char singleWord[1024];
    
        int index = 0;
        while (buff[index])
        {   
            if (length > 0 && buff[index] == ' ') {
                int setFlag = 1;
                for (size_t i = 0; i < count; i++)
                {
                    if (strcmp(words[i], singleWord) == 0) {
                        setFlag = 0;
                        wordsCounts[i]++;
                        break;
                    }
                }

                if (setFlag) {
                    strcpy(words[count], singleWord);
                    wordsCounts[count] = 1;
                    count++;
                }

                length = 0;
                memset(singleWord, 0, 1024);
            }

            if (buff[index] != ' ') {
                singleWord[length] = buff[index];
                length++;
                symbolCounts++;
            }
            index++;
        }

        if (buff[index] == '\0' && length) {
            int setFlag = 1;
            for (size_t i = 0; i < count; i++)
            {
                if (strcmp(words[i], singleWord) == 0) {
                    setFlag = 0;
                    wordsCounts[i]++;
                    break;
                }
            }

            if (setFlag) {
                strcpy(words[count], singleWord);
                wordsCounts[count] = 1;
                count++;
            }
        } 
    }

    printf("Symbol count: %ld  without spaces :%d \n", info.st_size, symbolCounts);

    for (size_t i = 0; i < count; i++)
    {
        printf("%s : %d \n", words[i], wordsCounts[i]);
    }

    int maxIndex = 0;
    int max = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (max < wordsCounts[i]) max = wordsCounts[i];
    }
    
    printf("Max word is: %s  with count :%d \n", words[maxIndex], wordsCounts[maxIndex]);
   
}
