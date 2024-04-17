#include <stdio.h>

#define SIZE 3  // Size of the square matrix

// Function to transpose a square matrix
void transposeMatrix(int matrix[SIZE][SIZE]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            // Swap the elements
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to reverse each row of the matrix
void reverseRows(int matrix[SIZE][SIZE]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            // Swap the elements
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][SIZE - 1 - j];
            matrix[i][SIZE - 1 - j] = temp;
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    // Mirror the matrix by the auxiliary diagonal
    transposeMatrix(matrix);
    reverseRows(matrix);

    printf("Mirrored Matrix by Auxiliary Diagonal:\n");
    printMatrix(matrix);

    return 0;
}