#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strcat_(char * a, char * b) {
    char * ptr = malloc(strlen(a) + strlen(b) + 1);
    int i = 0;
    while (a[i])
    {
        ptr[i] = a[i];
        i++;
    }
    int j = 0;
    while (b[j])
    {
        ptr[i] = b[j];
        i++;
        j++;
    }
    ptr[i] = '\0';
    return ptr;
}
void swap (int * a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int * removeDuplicate() {
    int size = 0 ;
    printf("Please enter arr size: ");
    scanf("%d", &size);
    int * arr = (int*) calloc(size, sizeof(int));
    for (int i = 0 ; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int j = 0 ;
    for (int i = 1 ; i < size; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] == arr[i];
        }
    }
    int finalSize = j + 1;
    arr = (int *) realloc(arr, finalSize);
    for (int i = 0; i < finalSize; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return arr;
}
int main () {
    int size = 5;
    int dummy_arr[5] = {1,2,2,2,4};
    removeDuplicate();
}