#include <stdio.h>
// 15. https://leetcode.com/problems/rotate-image/description/


void printArr(int arr[][3]) {
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    
}

void swap(int*a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate (int arr[][3]) {
    int size  = 3;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
           swap(&arr[i][j], &arr[j][i]);   
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0 ; j < size / 2; j++) {
            swap(&arr[i][j], &arr[i][size-1-j]);
        }
    }
    
}

int main () {
    int arr [][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(arr);
    printArr(arr);

}