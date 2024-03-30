#include <stdio.h>
#include <stdlib.h>

void * my_malloc(int n) {
    int* ptr = malloc(n * sizeof(n));
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** arr = (int**) malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int*) malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; ++i) {
        arr[i] = (int*) malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        if(arr == NULL) {
            exit(1);
        }
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}


int main () {
    int n = 0;
    scanf("%d", &n);

    int ** arr = (int**) calloc(n, sizeof(int*));
    int * returnColumnSizes;

    arr = generate(n, &n, &returnColumnSizes);

    for (int i = 0; i < n; i++) {
        for (int j = 0;  j < returnColumnSizes[i]; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    // for (int i = 0 ; i < 5; i++) {
    //     printf("%d", returnColumnSizes[i]);
    // }

}