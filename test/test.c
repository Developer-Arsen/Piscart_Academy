#include <stdio.h>
#include <stdbool.h>

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

int matrix(int * arr, int row, bool (*octal)(int)) {
    int count = 0;
    for (int i = 0; i < row * row; i++) {
        int a = i / row;
        int b = i % row;
        if (a + b > row -1) {
            count += octal(*(arr + b * row + a));
        }
    }

    return count;
}

int main () {
    const int size = 4;
    int arr[][4] = {
        {1,2,3,4},
        {1,2,3,5},
        {1,2,5,5},
        {1,2,5,2}
    };

    int res = matrix(arr[0], size, two_octal);
    printf("%d \n", res);
}