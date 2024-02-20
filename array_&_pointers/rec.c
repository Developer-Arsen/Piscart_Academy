#include <stdio.h>

void scan_arr(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_arr(int size, int * arr) {
    if (--size < 0) return;
    
    print_arr(size, arr);
    printf("%d \n", arr[size]);
}

void print_arr_reverse(int size, int * arr) {
    if (size < 0) return;
    
    printf("%d", arr[size]);
    print_arr_reverse(--size, arr);
}

void print_interval(int n) {
    if (n < 0) return;

    print_interval(n-1);
    printf(" %d ", n);
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp -1);
}

int find_arr_max(int size, int * arr) {
    if (size == 0) return arr[0];

    int max = find_arr_max(size-1, arr);
    return max < arr[size-1] ? arr[size-1] : max;
    
}

int find_arr_min(int size, int * arr) {
    if (size == 0) return arr[0];

    int min = find_arr_min(size-1, arr);
    return min < arr[size-1] ? min : arr[size-1];
    
}

int find_arr_mean(int size, int * arr) {
    if (size-1 == 0) return arr[0];

    int sum = sum + find_arr_mean(size-1, arr);
    return sum;
}

int binary_search(int size, int * arr, int target) {
    
}

int main () {
    // int x = 0;
    // scanf("%d", &x);

    // print_interval(x);
    // int sum = power(2, x);
    // printf("sum is : %d ", sum);

    const int size = 5;
    int arr[size];

    // scan_arr(size, arr);
    // int max = find_arr_max(size, arr);
    // printf("max is %d \n", max);

    // int min = find_arr_min(size, arr);
    // printf("min is %d \n", min);

    // int mean = find_arr_mean(size, arr);
    // printf("mean is %d \n", mean);



}