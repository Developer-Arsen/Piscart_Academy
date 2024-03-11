#include <stdio.h>

void swap_bits(int i, int j, int* n) {
    int bit1 = (*n >> i) & 1;
    int bit2 = (*n >> j) & 1;

    if (bit1 != bit2) {
        *n = *n ^ (bit1 << j);
        *n = *n ^ (bit2 << i);
    }
    printf("%d", *n);
}

int main () {
    int i = 4;
    int j = 1;
    int num = 15;
    swap_bits(i, j, &num);
}
