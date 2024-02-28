#include <stdio.h>
#define SIZE(arr) sizeof(arr) / sizeof(*arr);

void fun (int *arr, int n) {
    int i;
    *arr += *(arr + n -1) += 10;
} 

void printArr(int * arr, int size) {
    for (int i = 0 ; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main () {
    int arr[] = {10,20,30};
    int size = SIZE(arr);
    fun(arr, size);
    printArr(arr, size);
    return 0;
}