#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int**nums, int numsSize) {

    if (*nums == NULL || numsSize <= 0) {
        return 0;
    }

    int index = 0;
    for (int i = 1; i < numsSize; i++) {
        if ((*nums)[index] != (*nums)[i]) {
            index++;
            (*nums)[index] = (*nums)[i];    
        }
    } 

    *nums = (int *) realloc(*nums, index +1);
    return index + 1;
}

int main () {
    int len = 7;
    int * arr = (int *) malloc(sizeof(int) * len);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 4;
    arr[6] = 5;

    int size = removeDuplicates(&arr, len);
    for(int i = 0 ; i < size; i++) {
        printf("%d", arr[i]);
    }

    free(arr);
}