#include <stdio.h>

void saddlePoint(int arr[][3], int row, int column) {
    for (int i = 0 ; i < row; i++) {
        int flag = 0;
        
        for (int j = 0; j < column; j++) {
            int min = arr[i][j];

            for (int k = 0; k < row ; k++)
            {
                if (min > arr[i][k]) flag = 1;
            }
            
        }
        
    }
}

// 9 1 8
// 5 0 6
// 10 6 12