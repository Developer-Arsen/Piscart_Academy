#include <stdio.h>

int *gptr;

int main () {
    int *lptr = NULL;

    if (gptr == lptr) {
        printf("Equal \n");
    } else {
        printf("not Equal \n");
    }
}
