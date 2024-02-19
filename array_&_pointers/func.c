#include <stdio.h>

void scan_arr(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_arr(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void print_arr_count(int size, int * arr) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == -1) break;
        ++count;
    }
    printf("arr count is: %d", count);
}

void sum_pow (int base, int exp) {
    int sum = base;
    for (int i = exp; i != 1; i--) {
        sum *= base;
    }
    printf("sum is : %d", sum);
}

void swap_by_ref(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void equal_number_remove (int size, int *arr, int val) {
    for (int i = 0, j = size-1; i <= j; i++) {
        if (arr[i] == val) {
            swap_by_ref(&arr[i], &arr[j]);
            arr[j] = -1;
            i--;
            j--;
        }
    }
}

int main () {
    // int x = 10;
    // int y = 20;
    // scanf("%d", &x);

    // swap_by_ref(&x, &y);
    
    const int size = 5;
    int arr[size];

    scan_arr(size, arr);
    equal_number_remove(size, arr, 5);
    print_arr(size, arr);
    print_arr_count(size, arr);

    // print_arr(arr);


}