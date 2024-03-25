#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main () {
    char *error;
    int res = 0;
    int (*fptr) (int , int);
    
    void * hanle = dlopen("./example.so", RTLD_NOW);
    if (!hanle) {
        printf("%s\n", dlerror());
        exit(1);
    }

    fptr = dlsym(hanle, "mult");

    error = dlerror();
    if (error != NULL) {
        printf("%s\n", error);
        exit(1);
    }

   

    res = fptr(5,4);
    printf("%d", res);

    if (dlclose(hanle) < 0) {
        printf("%s\n", dlerror());
        exit(1);
    }

    

    return 0;
}