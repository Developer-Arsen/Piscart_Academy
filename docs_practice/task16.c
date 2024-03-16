#include <stdio.h>

void foo(int target, char c1, char c2, short sh) {

    char * ptr = (char*) &target;
    ptr[0] = c1;
    ptr[1] = c2;
    short * shptr = (short*) &target; 
    ptr[1] = sh;

    printf("%d \n", target);
}

int main () {

    int b = 0;
    foo(b, 1, 1, 1);
    
}