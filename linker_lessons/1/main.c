#include <stdio.h>
#include "mylib.h"

int main () {
    char upper[] = "maKe All Upper";
    char lower[] = "maKe All LOWer";

    char hex[7] = {"0x"};
    int decimal = 100;

    char * res = decimalToHex(decimal, hex);
    puts(res);
    
    // toUpper(upper);
    // toLower(lower);

    // puts(upper);
    // puts(lower);



}