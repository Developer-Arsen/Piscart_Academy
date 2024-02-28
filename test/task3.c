#include <stdio.h>

char * my_strcat(char *s1, const char *s2) {
    while (*s1)
    {
        s1++;
    }
    
    while (*s2)
    {
        *s1++ = *s2++;
    }
    *s1 = '\n';
    return s1;
}

int main () {
    char dest[20] = {"hello "};
    char src[] = {"wolrd"};

    my_strcat(dest, src);
    puts(dest);

}