#include <stdio.h>
#define SIZE 4
void swao (int * a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void mirorByRow(int arr[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size / 2 ; j++) {
            swao(&arr[i][j], &arr[i][size - 1 -j]);
        }
    }
}

void mirorByColumn(int arr[SIZE][SIZE], int size) {
    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < size ; j++) {
            swao(&arr[i][j], &arr[size - i -1][j]);
        }
    }
}

void mirorByMainDiaganal(int arr[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swao(&arr[i][j], &arr[j][i]);
        }
    }
}

void mirrorByAuxDiagonal(int arr[][SIZE], int size) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) { 
            if (i + j != size -1) {
                swao(&arr[i][j], &arr[size-1-j][size-1-i]);
            }
        }
    }
}

void rotateRight90(int arr[][SIZE], int size) {
   mirorByMainDiaganal(arr,size);
   mirorByRow(arr,size);
}

void rotateLeft90(int arr[][SIZE], int size) {
   mirrorByAuxDiagonal(arr,size);
   mirorByRow(arr,size);
}

int main () {
    int size = SIZE;
    // int arr[][SIZE] = {
    // {1,7,5,9,6,3,8,5,2},
    // {2,5,8,1,7,4,9,6,3},
    // {3,9,6,2,8,5,1,7,4},
    // {4,1,7,3,9,6,2,8,5},
    // {5,2,8,4,1,7,3,9,6},
    // {6,3,9,5,2,8,4,1,7},
    // {7,4,1,6,3,9,5,2,8},
    // {8,5,2,7,4,1,6,3,9},
    // {9,6,3,8,5,2,7,4,1}
    // };
    int arr [][SIZE] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}}; 

    for (int i = 0 ; i < size; i++) {
        for (int j = 0 ; j < size; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // mirorByRow(arr, size);
    // mirorByColumn(arr, size);
    // mirorByMainDiaganal(arr, size);
    // mirrorByAuxDiagonal(arr, size);
    // rotateRight90(arr, size);
    rotateLeft90(arr, size);
    
    for (int i = 0 ; i < size; i++) {
        for (int j = 0 ; j < size; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
 }