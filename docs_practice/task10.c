// 10. https://leetcode.com/problems/missing-number/description/


int missingNumber(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum += nums[i];
    }
    int limitSum = (numsSize) * (numsSize+1) / 2;
    return limitSum - sum;
}