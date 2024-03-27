// 8. https://leetcode.com/problems/maximum-subarray/

#include <stdio.h>

int subArray (int * arr, size_t size) {
    int max = arr[0];
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
        if (max < sum) {
            max = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    return max ;
    
}

int main () {

}