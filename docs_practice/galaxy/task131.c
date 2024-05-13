#include <stdio.h>
#include <stdlib.h>

int main() {
    setenv("MY_VAR", "arsen", 1);
    const char* var = getenv("MY_VAR");

    if (var != NULL) {
        printf("MY_VAR: %s\n", var);
    } else {
        printf("MY_VAR is not set.\n");
    }
    return 0;
}
