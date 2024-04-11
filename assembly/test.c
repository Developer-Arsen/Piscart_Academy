#include <stdio.h>

void swap_ (char * a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main () {
    char arr[] = {"hello"};
    int size  = 6;
    for (int i = 0 ; i < size / 2 ; i++) {
        swap_(&arr[i], &arr[size-i-2]);
    }

    for (int i = 0 ; arr[i] ; i++) {
        printf("%c", arr[i]);
    }
}