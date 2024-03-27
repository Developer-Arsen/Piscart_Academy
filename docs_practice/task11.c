#include <stdio.h>

// 11. https://leetcode.com/problems/search-insert-position/description


void swap(int * a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int * selectionSort(int * arr, int size) {
    int min = 0;
    int index = 0;

    for (int i = 0 ; i < size -1 ; i++) {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < size; j++) {
            if (min > arr[j]) { index = j; }
        }

        if (index != i) {
            swap(&arr[i], &arr[index]);
        }
    }

    return arr;
}

int main () {
    // int arr[] = {1,4,2,7,5};
    double arr[20000000];
    

    // selectionSort(arr, 5); 

    // for (int i = 0; i < 5; i++) {
    //     printf("%d", arr[i]);
    // }
}