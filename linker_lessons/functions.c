#include <stddef.h>
#include <string.h>

/* Make string to Upperace */
void toUpper(char * src) {
    if (src == NULL) return;

    int i = 0;
    while (src[i])
    {
        if (src[i] >= 'a' && src[i] <= 'z') {
            src[i] -= 32; 
        }
        i++;
    }
}

/* Make string to Lowercase */
void toLower(char * src) {
    if (src == NULL) return;

    int i = 0;
    while (src[i])
    {
        if (src[i] >= 'A' && src[i] <= 'Z') {
            src[i] += 32; 
        }
        i++;
    }
}

/* from given integer make decimal representation */
char * decimalToHex(int n , char * hex) {
    if (!n) return 0;
    decimalToHex(n / 16, hex);
    
    int val = n % 16;
    if (val < 10) hex[strlen(hex)] = val + 48;
    else hex[strlen(hex)] = val + 55;

    return hex;
}