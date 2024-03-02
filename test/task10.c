#include <stdio.h>

void swap_by_ref(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_by_val(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main () {
    int a  = 10;
    int b  = 15;

    swap_by_ref(&a, &b);
    swap_by_val(a, b);
}