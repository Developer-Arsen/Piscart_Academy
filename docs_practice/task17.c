#include <stdio.h>
char reverse (char n) {
    char number = 0;
    int count = 7;
    while (count > -1) {
        char digit = n & 1;
        n >>= 1;

        digit <<= count;
        number |= digit;
        count--;
    }
    return number;
}
int main () {
    char res = reverse(0b00001111);
    printf("%d \n", res);
}