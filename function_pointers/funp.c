#include <stdio.h>
#include <stdbool.h>

// at home to do 
// int matrix(int * arr, int row, bool (*octal)(int)) {
//     int count = 1;
//     for (int i = 0; i < row * row; i++) {
//         int a = i / row;
//         int b = i % row;
//         if (a < b) {
//             if (octal(*(arr + b * row + a))) {
//                 printf("%d \n", *(arr + b * row + a));
//                 // count *= *(arr + b * row + b);
//             }
//         }
//     }
//     return count;
// }

bool two_octal(int n) {
    while (n)
    {
        if (n % 8 != 2) {
            return false; 
        }
        n /= 8;
    }
    return true;
}

bool is_palindrome(int n) {
    int num = n;
    int sum = 0;
    if (n / 10 == 0) return true;

    while (num)
    {
        sum *= 10; 
        sum += num % 10;
        num /= 10;
    }
    return sum == n;
}

bool is_fibonachi(int n) {
    if (n == 0) return true;
    int a = 0;
    int b = 1;
    
    while (a < n)
    {
        int tmp = a + b; 
        a = b; 
        b = tmp; 
    }
    return a == n;
}

int fibonachi_recursive_by_caching(int n) {
    static int arr[20] = {0, 1};
    
    if (arr[n] != 0) return arr[n];
    if (n == 0) return 0;
    arr[n] = fibonachi_recursive_by_caching(n - 1) + fibonachi_recursive_by_caching(n-2);
    return arr[n];
}

int factorial_recursive_by_caching(int n) {
    static int arr[20] = {1, 1};
    
    if (arr[n] != 0) return arr[n];
    if (n == 1) return 1;
    arr[n] = factorial_recursive_by_caching(n-1) * n;
    return arr[n];
}

int matrix_main_diaganal_up_palindrome_mult(int arr[][4], int row, bool (*fptr)(int)) {
    int count = 1;
    for (int i = 0; i < row; i++) {
       for (int j = 0; j < row; j++) {
            if (i < j) {
                if (fptr(arr[i][j])) {
                   count *= arr[i][j];
                }
            }
       } 
    }
    return count;
}

void matrix_main_diaganal_up_fib(int arr[][4], int row, bool (*fptr)(int)) {
    int count = 1;
    for (int i = 0; i < row; i++) {
       for (int j = 0; j < row; j++) {
            if (i < j) {
                if (fptr(arr[i][j])) {
                    printf("%d \n", arr[i][j]);
                }
            }
       } 
    }
}


void printSum(int a, int b) {
    printf("%d \n", a+b);
}


int main () {
    void (*arsen) (int, int);
    printSum(4,5);
    arsen = printSum;
    arsen(4,5);

    char * str = "hello"; 
    char str2[20] = "hello";
    // const int size = 4;
    // int arr[][4] = {
    //     {1,2,2,2},
    //     {1,1,2,2},
    //     {1,1,1,2},
    //     {1,1,1,1}
    // };

    // // matrix_main_diaganal_up_fib(arr, size, is_palindrome);
    // // int res = matrix_main_diaganal_up_palindrome_mult(arr, size, is_palindrome);
    // // printf("%d \n", res);

    // int res = factorial_recursive_by_caching(5);
    // // 0 1 1 2 3 5 8 13
    // printf("%d \n", res);

}