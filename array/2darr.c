#include <stdio.h>
const int size = 3;

void swap_by_ref(int * x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void scan_arr (int arr[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_arr (int arr[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}

void sum_main_diaganal(int arr[][size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][i];
    }
    printf("main diaganal sum = %d \n", sum);
}

void sum_aux_diaganal(int arr[][size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][size-1-i];
    }
    printf("auxiliary diaganal sum = %d", sum);
}

void reverse_diaganals(int arr[][size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        swap_by_ref(&arr[i][i], &arr[i][size-i-1]);
    }
}

void rotate_matrix_by_90(int arr[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++) {
            swap_by_ref(&arr[i][0], &arr[i][size-i-1]);
        }
    }
}

void sum_main_diaganal_dawn(int (*arr)[size], int row) {
    int sum = 0;
    for (int i = 0; i < row * row; i++) {
        int a  = i / row;
        int b  = i % row;
        if (a > b) sum += arr[a][b];
    }

    printf("main diaganal under sum = %d \n", sum);
}

void sum_main_diaganal_up(int (*arr)[size], int row) {
    int sum = 0;
    for (int i = 0; i < row * row; i++) {
        int a  = i / row;
        int b  = i % row;
        if (a < b) sum += arr[a][b];
    }

    printf("main diaganal up sum = %d \n", sum);
}

void sum_aux_diaganal_up(int (*arr)[size], int row) {
    int sum = 0;
    for (int i = 0; i < row * row; i++) {
        int a  = i / row;
        int b  = i % row;
        if (a + b < row- 1 ) sum += arr[a][b];
    }

    printf("auxiliary diaganal up sum = %d \n", sum);
}

void sum_aux_diaganal_down(int (*arr)[size], int row) {
    int sum = 0;
    for (int i = 0; i < row * row; i++) {
        int a  = i / row;
        int b  = i % row;
        if ( a + b > row -1) sum += arr[a][b];
    }

    printf("auxiliary diaganal up sum = %d \n", sum);
}



int main () {

    int arr [size][size];
    scan_arr(arr);
    print_arr(arr);

    sum_aux_diaganal_up(arr, size);

    
    
}