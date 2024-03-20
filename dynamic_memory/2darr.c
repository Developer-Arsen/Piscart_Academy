#include <stdio.h>
#include <stdlib.h>

int ** scanArr (int row, int column) {
    int ** arr = (int**) calloc(row, sizeof(int*));
    
    for (int i = 0 ; i < row; i++) {
        arr[i] = (int *) calloc(column, sizeof(int));
    }
   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

void printArrSnakable (int ** arr, int row, int column) {
    int flag = 1;
    for (int i = 0; i < row; i++) {
        if (flag > 0) {
            for (int j = 0; j < column; j++) {
                printf("%d", arr[i][j]);
            }
        } 
        else {
            for (int j = column - 1; j >= 0; j--) {
                printf("%d", arr[i][j]);
            }
        }
        flag *= -1;
        printf("\n");
    }
}

void freeMatrix (int **arr, int size) {
    for (int i = 0 ; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}

int * madeArrByMatrixRowMaxElement(int **arr, int row, int column) {
    int* new_arr = (int*) calloc(row, sizeof(int));

    int max = 0;
    for (int i = 0; i < row; i++) {
        max = arr[i][0];
        for (int j = 0; j < column; j++) {
            max = max > arr[i][j] ? max : arr[i][j];
        }
        new_arr[i] = max;
    }
    return new_arr;
}

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
}



int main () {
    int row = 3;
    int column = 4;
    int ** arr;
    int * new_arr;

    arr = scanArr(row, column);
    printArrSnakable(arr, row, column);

    new_arr = madeArrByMatrixRowMaxElement(arr, row, column); 

    printArr(new_arr, row);
    freeMatrix(arr, row);
    
    free(new_arr);

    

}