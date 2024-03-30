#include <stdio.h>
#include <stdlib.h>

int fibonachi(int n, int * fibArr) {
    if (fibArr[n] != 0) return fibArr[n];
    if (n == 0) return 0;
    fibArr[n] = fibonachi(n-1, fibArr) + fibonachi(n-2, fibArr);
    return fibArr[n];
}

int main () {
    int n = 0;
    scanf("%d", &n);

    int ** arr = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) calloc(n, sizeof(int));
    }
    
    int * fibArr = (int *) calloc(n*n, sizeof(int));
    fibArr[0] = 0;
    fibArr[1] = 1; 
   
    int count = n*n -1;
    for (int i = n -1 ; i >= 0; i--) {
        for (int j = n -1 ; j >= 0; j--) {
            arr[i][j] = fibonachi(count-- , fibArr);
        }
    }

    printf("\n");
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}