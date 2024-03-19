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

int main () {
    int size = 5;
    int dummy_arr[5] = {1,2,2,2,4};

    int * arr = malloc(5 * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = dummy_arr[i];
    }

    // i = 1
    // number 2
    // j = 2

    // 1 2 2 2 2
    // 1 2 2 2 -1
    // 1 2 2 2 -1
    // for (int i = 0; i < size -1; i++) {
    //     int number = arr[i];

    //     for (int j = i + 1; j <= size - i; j++) {
    //         if (number == arr[j]) {
    //             arr[j] = -1;
    //             swap(&arr[j], &arr[size - i]); 
    //             i++;
    //         }
    //     }
    //     if (number == arr[i-1] && arr[i+1] == -1)
    // }

    // for (int i = 1; i < size; i++)
    // {
    //     if (arr[i] == arr[i-1]) {
    //         arr[i] = -1;
    //         swap(&arr[i], &arr[size - i]);
    //     }
    // }
    


    // for (size_t i = 0; i < size; i++)
    // {
    //     printf("%d", arr[i]);
    // }

    // // printf("\n %d \n", final_size);
    
   
    

}