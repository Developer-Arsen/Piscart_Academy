#include <stdio.h>

int str_len (const char * s) {
    if (s == NULL || *s == '\0') return 0;
    int count = 1 + str_len(s + 1);
    return count;
}

int main () {
    char arr[100];

    int res = str_len("barev");
    printf("%d", res);
}