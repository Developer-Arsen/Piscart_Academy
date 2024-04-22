#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int factorial(int n);
int printMainDiaganal(int ** mat, int size);

int main (int argc, char* argv[]) {
    __pid_t id = 0;

    id = fork();
    if (id == 0) {
        int flag = 1;

        do
        {
            char * command = (char *) malloc(sizeof(char) * 10);
            fgets(command, 10, stdin);
            
            command[strcspn(command, "\n")] = 0;
            system(command);
            if (!strcmp(command, "exit")) {
                flag = 0;
            }
        } while (flag);
        
        
        // char* path = "/usr/bin/ps";
        // char* args[] = {"ps", "-ef", NULL};
        // execv(path, args);
        // exit(0);
        // system(name);
        // printf("%s", strerror(errno));
        // execl("/usr/bin/vi", "vi",  "/home/arsen/Piscart_Academy/docs_practice/Processes/test.c", NULL);
        // execl("/usr/bin/ps", "-ef", NULL);
        // system("ls");
    } else if (id > 0) {
        wait(NULL);
        printf("\n parent");
    }



    // argc and argc tasks
    // int * arr = (int*)malloc((argc -1) * sizeof(int));

    // for (size_t i = 0; i < argc; i++)
    // {
    //     arr[i] = atoi(argv[i+1]) + 5;
    // }
    
    // for (size_t i = 0; i < argc -1; i++)
    // {
    //     printf("%d", arr[i]);
    // }
    // printf("\n");
    // argc and argc tasks

    // __pid_t pid = 0;
    // __pid_t childId = 0;

    // pid = fork();
    // if (pid < 0) {
    //     perror("error");
    //     exit(1);
    // }
    // else if (pid == 0) {
    //     childId = fork();
    //     if (childId < 0) {
    //         perror("child error");
    //     } else if (childId == 0) {
    //         printf("I am child %d factorial value is: %d  \n", getpid(), factorial(5));
    //         exit(0);
    //     }

    //     int size = 3;
    //     int ** mat = (int**) malloc(size * sizeof(int*));
    //     for (size_t i = 0; i < size; i++)
    //     {
    //         mat[i] = (int*) malloc(size* sizeof(int));
    //     }

    //     wait(NULL);
    //     printMainDiaganal(mat, size);
    //     printf("I am child %d \n", getpid());
    //     exit(0);
    // }
    // else if (pid > 0) {
    //     wait(NULL);
    //     printf("I am parent %d \n", getpid());
    // }
}


int factorial (int n){
    if (n == 1) return 1;
    return n * factorial(n -1);
}

int printMainDiaganal(int ** mat, int size) {
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            mat[i][j] = count++;
        }
    
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%d", mat[i][j]); 
        }
        printf("\n");
    }
    printf("\n");

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i == j) printf("%d", mat[i][j]); 
        }
    }
    printf("\n");
}