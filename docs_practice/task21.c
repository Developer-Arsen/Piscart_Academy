// 21. Գրել ֆունկցիա, որը կկատարի թվի աստճանի բարձրացում՝ բիթային։
#include <stdio.h>
#include <stdlib.h>

int bit_mul(int a, int b) {
    int result = 0;
    while (b != 0) {
        if (b & 1) {
            result = bit_add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int bit_exponent(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = bit_mul(result, base);
        }
        base = bit_mul(base, base);
        exponent >>= 1;
    }
    return result;
}

int main() {
    printf("%d\n", bit_mul(5, 3));  
    printf("%d\n", bit_exponent(3, 5));  
    return 0;
}