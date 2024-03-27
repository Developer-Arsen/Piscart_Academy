#include <stdio.h>
// 2.Ստուգել թվի 1 արժեքով բիթերի քանակը կենտ է, թե զույգ:

void count_odd_bits (int n) {
    int count = 0;

    while (n)
    {
        count += n & 1; 
        n /= 2;
    }
    
    if (!(count % 2)) {
        puts("Even");
    } else puts("Odd");

}

int main () {
    int n = 4;
    count_odd_bits(n);
}