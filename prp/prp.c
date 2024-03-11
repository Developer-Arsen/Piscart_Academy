#include <stdio.h>
#include <stdbool.h>


void swap_my (int * a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubleSort(int * arr, int size) {
    int flag = 0 ;

    for (int i = 0; i < size; i++) {
        flag = 0 ;
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                swap_my(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
    } 
}

void selectionSort (int * arr, int size) {
    int index  = 0;
    for (int i = 0; i < size -1; i++) {
        index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[index]) index = j;
        }

        if (index != i) {
            swap_my(&arr[i], &arr[index]);
        }
    }
}

// int binarySearch (int * arr, int size, int target) {
//     int start = 0;
//     int end = size -1;
//     int mid = 0;

//     while (start <= end) {
//         mid = (start + end) / 2;

//         if (arr[mid] == target) return mid;

//         if (target > arr[mid]) start = mid + 1;
//         else end = mid - 1;
//     }

//     return -1;
// }

int binarySearch (int * arr, int start, int end, int target) {
    if (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) return mid;
        
        if (target > arr[mid]) return binarySearch(arr, mid + 1, end, target);
        else return binarySearch(arr, start, mid - 1, target);
    }
    return -1;
}



void print_arr (int *arr, int size) {
    for (int i = 0 ; i < size; i++) {
        printf("%d  ", arr[i]);
    }
}

int main () {
    int arr[] = {1,5,7,4,6};

    int res = binarySearch(arr, 0, 4, 5);
    printf("%d", res);
    // print_arr(arr, 5);


}