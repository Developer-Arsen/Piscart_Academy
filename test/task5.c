#include <stdio.h>

int my_strlen(const char * src) {
    int count = 0;
    while (*src++)
    {
        count++;
    }
    return count;
}


int search_patt(const char * src, const char * patt) {
    int src_length = my_strlen(src);
    int patt_length = my_strlen(patt);
    if (patt_length > src_length) return -1;

    int i = 0, j;

    while (i <= src_length - patt_length)
    {
        j = 0;
        while (j < patt_length && src[i+j] == patt[j])
        {
            j++;
        }

        if (j == patt_length) {
            return i;
        }
        
        i++;
    }
    return -1;
}

int main () {
    char src[] = "Apple Pie";
    char patt[] = "Pie";

    int res  = search_patt(src, patt);
    printf("%d", res);
}