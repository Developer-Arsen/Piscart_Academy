#include <stdio.h>

int max (int a, int b) {
    return a > b ? a : b;
}

int rob (int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int arr[numsSize];
    arr[0] = nums[0];
    arr[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        arr[i] = max(arr[i-2] + nums[i], arr[i-1]);
    }

    return arr[numsSize-1];

}
