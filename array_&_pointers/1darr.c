#include <stdio.h>

void swap_by_ref(int * x, int * y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

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

void find_mean(int size, int * arr) {
    int mean = 0;
    for (int i = 0; i < size; i++) {
        mean += arr[i];
    }
    printf("mean is : %d \n", mean / size);
}

void find_min(int size, int * arr) {
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        min = arr[i] < min ? arr[i] : min;
    }
    printf("min is : %d \n", min);
}

void find_max(int size, int * arr) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        max = arr[i] > max ? arr[i] : max;
    }
    printf("max is : %d \n", max);
}

void reverse_arr(int size, int * arr) {
    for (int i = 0; i < size / 2; i++) {
        swap_by_ref(&arr[i], &arr[size-i-1]);
    }
}

void find_missing_value(int size, int * arr) {
    int intervalSum = (arr[0] + arr[size-1]) * (size + 1) / 2;
    // s = (a1 + an) * size / 2
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("missing value is %d", intervalSum - sum);
}

void find_unique (int size, int * arr) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        flag ^= arr[i];
    }
    printf("unique value is %d", flag);
}

void findBestProfit (int size, int * arr) {
    int min = arr[0];
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            printf("Ars");
            min = arr[i];
        }
        max = arr[i] - min > max ? arr[i] - min : max;
    }
    printf("best profit is: %d", max);
}

void sort_by_evens_no_consecutive(int size, int * arr) {
    for (int i = 0, j = size-1; i < j;) {
        if (arr[i] % 2 == 0) {
            swap_by_ref(&arr[i], &arr[j]);
            j--;
        } else i++;
    }
}

void sort_by_evens_consecutive(int size, int * arr) {
    for (int i = 0, j = 1; i <= size / 2 && j <= size;) {
        if (arr[i] % 2 == 0) {
                swap_by_ref(&arr[i], &arr[i+j]);
                j++;
        } else i++;
    }
}
    
void find_biggest_area(int size, int * arr) {
    int max = 0;
    for (int i = 0, j = size-1; i < j;) {
        int distance = (j-i);
        if (arr[i] > arr[j]) {
            max = distance * arr[j] > max ? distance * arr[j] : max;
            j--;
        }
        else if(arr[j] >= arr[i]) {
            max = distance * arr[i] > max ? distance * arr[i] : max;
            i++;
        }
    }

    printf("biggest area is: %d", max);
}

int binary_search(int size, int *arr, int target) {
    int mid = 0;
    int start = 0;
    int end = size -1; 

    while (start <= end) {
        mid = (start - end) / 2 + start;

        if (target == arr[mid]) return mid;

        if (target > arr[mid]) start = mid + 1;
        else end = mid -1;
    }

    return -1;
}

int main () {
    const int size = 5;
    int arr[size];
    int x = 4;

    scan_arr(size, arr);
    int target = binary_search(size, arr, x);
    printf("%d", target);

    // print_arr(size, arr);
    return 0;
}