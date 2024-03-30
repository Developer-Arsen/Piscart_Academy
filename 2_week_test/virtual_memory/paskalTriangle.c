#include <stdio.h>
#include <stdlib.h>

void * my_calloc(int n, int size) {
    char * ptr = (char*) malloc(n * size);

    if (ptr == NULL) {
        return NULL;
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = 0;
    }
    return ptr;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows <= 0) return NULL;

    int ** arr = (int**) my_calloc(numRows, sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes = (int *) my_calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        arr[i] = (int *) my_calloc(i + 1, sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        arr[i][0] = 1;
        arr[i][i] = 1;

        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    return arr;
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