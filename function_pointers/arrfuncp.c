#include <stdio.h>
#include <stdbool.h>

typedef double(*fptr) (int, int);

double sub(int a , int b ) {
    return a - b;
}

double add(int a , int b ) {
    return a + b;
}

double mul(int a , int b ) {
    return a * b;
}

int main () {
    fptr arr[] = {add, sub, mul};
    double (*fp[]) (int , int) = {add, sub, mul};

    double (*p[3]) (int, int);
    p[0] = add;
    p[1] = sub;
    p[2] = mul;


    for (int i = 0; i < 3; i++) {
        printf("%g \n", arr[i](1,2));
    }
}