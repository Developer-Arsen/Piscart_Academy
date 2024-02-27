#include <stdio.h>
#include <string.h>

size_t str_len(const char * str) {
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

int mem_cmp(const char * dest, const char * src, size_t n) {
    for (int i = 0; i < n; i ++) {
        if (dest[i] != src[i]) return i;
    }
    return 0;
}

// char * str_chr (const char * src, int c) {
//     int i = 0;
//     while (src[i] != (char) c) {
//         if (!src[i++]) return NULL;
//     }

//     return (src + i);
// }

char * str_cat (char * dest , const char * src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    int j = 0;
    while (src[j] != '\0') 
    {
        dest[i++] = src[j++];
    }
    return dest;
}

char * lesson_str_cat(char * dest, const char * src) {
    char * tmp = dest;
    
    while(*tmp != '\0') {
        tmp++;
    }

    while (*src != '\0')
    {
        *tmp++ = *src++;
    }
    return dest;
}
void * mem_cpy (void * dest, const void * src, size_t n ) {

    char * tmp = dest;
    const char * ptr = src;

    while (n--)
    {
        *tmp++ = *ptr++;
    }

    return dest;
}


int main () {
    char src[] = "Hello";
    char dest[10] = {"ars"};
   
    lesson_str_cat(dest, src);
    strcat();
    puts(dest);

    // char * a  = strchr(src, 'e');
    // char * b  = str_chr(src, 'e');
    // printf("%d       %d", *a, *b);

    // int original = memcmp(dest, src, 10);
    // int result = mem_cmp(dest, src, 10);
    // printf("%d        %d", original, result);
    // puts(b);
    // str_cp(str, copy); 
    // fgets(str, sizeof(str), stdin);
    // int count = str_len(str);
    // printf("%s \n", copy);
    // puts(copy);


}