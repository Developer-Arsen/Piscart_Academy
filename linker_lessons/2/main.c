#include "header.h"

int main () {
    const int size = 3;
    int arr[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    saddlePoint(arr, size, size);
}