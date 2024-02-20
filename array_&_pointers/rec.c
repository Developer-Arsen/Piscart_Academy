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

int binary_search(int * arr, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right-left) / 2;

        if (target == arr[mid]) return mid;

        if (arr[mid] > target)
            return binary_search(arr, left, mid-1, target);

        return binary_search(arr, mid + 1, right, target);
    }
    return -1;
}

int print_binary (int n) {
    if (n == 0) return 0;

    print_binary(n / 2); 
    printf("%d", n % 2);
}

int main () {
    // int x = 0;
    // scanf("%d", &x);

    // print_interval(x);
    // int sum = power(2, x);
    // printf("sum is : %d ", sum);

    // const int size = 5;
    // int arr[size];

    // scan_arr(size, arr);
    // int max = binary_search(arr, 0, size-1, 4);
    // printf("index is %d \n", max);
    // int b = 10;
    // int const* const a = &b;
    // int c = 0;
    // *a = 10;

    // int min = find_arr_min(size, arr);
    // printf("min is %d \n", min);

    // int mean = find_arr_mean(size, arr);
    // printf("mean is %d \n", mean);
    print_binary(5);



}