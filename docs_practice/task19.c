#include <stdio.h>
// 19. Քառակուսային մատրիցի գլխավոր և օժանդակ անկյունագծերի տարրերի արժեքները տեղերով փոխել։

void printArr(int arr[][3]) {
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    
}

void swap(int*a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseDiaganals (int arr[][3]) {
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (i+j == 3-1) {
                swap(&arr[i][i], &arr[i][j]);
            }            
        }
    }
}

int main () {
    int arr [][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    reverseDiaganals(arr);
    
    printArr(arr);

}