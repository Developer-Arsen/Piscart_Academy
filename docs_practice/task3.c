#include <stdio.h>

int reverse (int num) {
    int res = 0;
    while (num)
    {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

int palindrome_count(int n) {
    int count = 0;

    while (n != reverse(n)) {
        n += reverse(n);
        count++;
    }
    return count;
}


int main () {
    int n = 18;
    int res = palindrome_count(n);
    printf("%d \n", res);
    
}