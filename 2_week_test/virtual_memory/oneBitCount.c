#include <stdio.h>
#include <stdlib.h>

int countOneBits(int num) {
    int count = 0;
    // int i = 0;
    // while (num) {
    //     count += num & (1 << i); 
    // }
    while (num) {
        num = num & (num -1);
        count++;
    }
    return count;
}

int * countBits(int n, int* returnSize) {
    int * arr = (int*) calloc(n + 1, sizeof(int));
    if (arr == NULL) {
        printf("Eroor");
        exit(1);
    }
    *returnSize = n + 1;

    for (int i = 0 ; i < n + 1; i++) {
        arr[i] = countOneBits(i);
    }

    return arr;
}

int main () {
    int n = 0 ;
    int size = 0;
    scanf("%d", &n);
    int * arr = countBits(n, &size);

    for (int i = 0 ; i < size; i++) {
        printf("%d", arr[i]);
    }

    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}