#include <stdio.h>
#include <stddef.h>

int myAtoi(char * s) {
    if (s == NULL || *s == '\0') return 0;

    int i = 0;
    while (s[i] == ' ') {
        i++ ;
    }

    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
    }

    long long result = 0;
    while (s[i] > '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        if (sign == 1 && result > __INT_MAX__) {
            return __INT_MAX__;
        }
        else if (sign == -1 && -1 * result < __INT_MAX__ * -1) {
            return __INT_MAX__ * -1;
        }
        i++;
    }

    return sign * result;

}

int main () {

}