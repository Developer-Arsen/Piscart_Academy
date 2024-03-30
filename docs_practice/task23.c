#include <stdio.h>
#include <stdlib.h>

// 23. Գրել ֆունկցիա, որը ստանում է զանգված և էլեմենտ։ Ավելացնել էլեմենտը զանգվածի վերջից։ Եթե զանգվածում տեղ չկա մեծացնել զանգվածը նոր ավելացնել։(push_back)


void push_back (int digit, int* arr, size_t * size, size_t * capacity) {
    if ((*capacity / sizeof(int)) < *size) {
        arr[*capacity / sizeof(int)] = digit;
        *capacity += sizeof(int);
        return;
    } 

    *size += 1;
    *capacity += sizeof(int);
    arr = (int *) realloc(arr, (*size) * sizeof(int));
    arr[*size -1] = digit;
    
}
int main () {
    size_t size = 2;
    size_t capacity = 0;

    int * arr = (int*) calloc(size, sizeof(int));

    push_back(10, arr, &size, &capacity);
    push_back(15, arr, &size, &capacity);
    push_back(20, arr, &size, &capacity);
    push_back(25, arr, &size, &capacity);
    
    
    for (int i = 0 ; i < size; i++) {
        printf("%d \n",arr[i]);
    }
}