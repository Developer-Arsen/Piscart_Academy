#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isPrime (int num) {
    if (num <= 1) return false;

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return  false;
    }

    return true;
}

int * primeArray(int size) {
    if (size <= 0) return NULL;

    int * arr = (int*) malloc(sizeof(int) * size);

    if (arr == NULL) { 
        printf("coulnd not allocate space");
        exit(1);
    }

    int count = 0;
    int num = 2;
    while (count < size) {
        if (isPrime(num)) {
            arr[count++] = num; 
        }
        num++;
    }
    return arr;
}


int main () {
    int size = 0;
    scanf("%d", &size);

    int * arr = primeArray(size);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}