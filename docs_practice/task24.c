#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void * my_realloc(void * ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    size_t old_size = malloc_usaable_size(ptr);
    if (old_size > size) {return ptr;}

    char * new = (char*) malloc(size);
    if (new == NULL) {
        printf("_______");
        exit(1);
    }

    size_t copy_size = old_size < size ? old_size : size;

    for (int i = 0 ; i < copy_size; i++) {
        new[i] = *((char*)ptr[i]);
    }

    // size_t* newSize = (unsigned *) (*(ptr-1));

}



int main () {

    int * arr = (int *) malloc(4);
    printf("%d", realloc(arr, 10));
}