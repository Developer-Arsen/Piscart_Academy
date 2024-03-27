#include <stdio.h>
// 14. Insertion sort

void insertionSort (int * arr, int size) {

    for (size_t i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // {8,4,9,5,7,6,3,2}
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

void printArr(int *arr, int size) {
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    
}

int main () {
    int size = 8;
    int arr[] = {8,4,9,5,7,6,3,2};
    insertionSort(arr, size);
    printArr(arr, size);
}