#include <stdio.h>

int main () {
    int arr[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (size_t i = 0 ; i < 3; i++) {
        int max = 0;
        int indexI = 0;
        int indexJ = 0;
        for (size_t j = 0; j < 3; j++)
        {
            if (max < arr[i][j]) {
                max = arr[i][j];
                indexI = i;
                indexJ = j;
            }
        }

        int flag = 0;
        for (size_t i = 0; i < 3; i++)
        {
            if (arr[indexI][indexJ] > arr[i][indexJ]) {
                flag = 1;
                break;
            }
        }
        
        if (flag) {
            printf("%d", arr[indexI][indexJ]);
            break;
        }
    }
}