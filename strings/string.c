#include <stdio.h>

int str_len(const char * str) {
    int count = 0;
    while (*(str + count) != '\0')
    {
        count++;
    }
    return count;
}

void str_cp(const char * src, char * dest) {
    int i = 0;
    while (*src != '\0') 
    {
        dest[i++] = *src++;
        // dest[i] = *src;
        // src++
        // i++
    }
    dest[i] = '\0';
}

int main () {
    char str[] = "Hello";
    char copy[6];

    str_cp(str, copy); 
    // fgets(str, sizeof(str), stdin);
    // int count = str_len(str);
    // printf("%s \n", copy);
    // puts(copy);


}