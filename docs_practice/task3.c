#include <stdio.h>
// 3.Գրել ֆունկցիա, որը ստանում է ամբողջ թիվ (int), այդ թվին գումարում նրա reverse֊ը, քանի դեռ չի ստացել պոլինդրոմ արժեք, և վերադարձնում է քայլերի քանակը, այդ արժեքին հասնելու համար։ օր․՝ 
// 1) 123 + 321 = 444 ստացանք պոլինդրոմ և վերադարձրինք 1         
// 2) 555 պոլինդրոմ է, վերադարձրինք 0         
// 3) 49 + 94 = 143, պոլինդրոմ չէ, հետևաբար 143 + 341 = 484, ստացանք պոլինդրոմ և վերադարձրինք 2։



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