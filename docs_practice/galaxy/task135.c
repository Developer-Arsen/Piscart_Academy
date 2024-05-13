#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int factorial(int n);
int printMainDiaganal(int ** mat, int size);



int main() {
    __pid_t pid = 0;
    __pid_t first_child;
    __pid_t second_child;

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        first_child = getpid();
        printf("I am child %d  factorial of 5 is: %d \n", getpid(), factorial(5));
        exit(EXIT_SUCCESS);
    }
    else {
        int first_status = 0;
        waitpid(pid, &first_status, WUNTRACED);

        pid = fork();
        if (pid < 0) {
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            second_child = getpid();

            int size = 3;
            int ** mat = (int**) malloc(size * sizeof(int*));
            for (size_t i = 0; i < size; i++)
            {
                mat[i] = (int*) malloc(size* sizeof(int));
            }
            printMainDiaganal(mat, size);
            printf("I am child %d \n", getpid());
            exit(EXIT_SUCCESS);
        } else {
            int second_status = 0;
            waitpid(pid, &second_status, WUNTRACED);
            printf("All is done %d         %d\n", pid, second_child);
        }
    }
    
    return 0;
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