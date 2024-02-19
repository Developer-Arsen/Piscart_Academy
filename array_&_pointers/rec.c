#include <stdio.h>

void scan_arr(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_arr(int size, int * arr, int start) {
    if (size == start) return;
    
    printf("%d", arr[start]);
    print_arr(size, arr, ++start);
}

void print_arr_reverse(int size, int * arr) {
    if (size == -1) return;
    
    printf("%d", arr[size]);
    print_arr_reverse(--size, arr);
}

void print_interval(int n) {
    if (n < 0) return;

    print_interval(n-1);
    printf(" %d ", n);
}

int power(int base, int exp) {
    if (exp == 1) return base;
    return base * power(base, exp -1);
}



int main () {
    int x = 0;
    scanf("%d", &x);

    print_interval(x);
    // int sum = power(2, x);
    // printf("sum is : %d ", sum);

    // const int size = 5;
    // int arr[size];

    // scan_arr(size, arr);
    // print_arr(size, arr, 0);



}