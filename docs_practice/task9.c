// 9. https://leetcode.com/problems/add-digits/description/

int addDigits(int num) {
    if (num == 0) return 0;

    int sum = 0;
    int res = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }

    if (sum < 10) return sum;
    sum = addDigits(sum);

    return sum;
}

int main () {
    
}