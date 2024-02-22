#include <stdio.h>


void scan_arr (int size, int * arr) {
    for (int i = 0 ; i < size; i++) {
        scanf("%d", arr + i);
    }
}

void print_arr (int size, int * arr) {
    for (int i = 0 ; i < size; i++) {
        printf("%d", *(arr + i));
    }
}

void print_addreses(int * a, char * b, double *c) {
    printf("a address is: %p \n", a);
    printf("b address is: %p \n", b);
    printf("c address is: %p \n", c);
}

void print_val_by_ref(int * x) {
    printf("value is : %d", *x);
}

void arithmetic_actions_by_ref(int * x , int *y) {
    printf("val 1 + val2 is : %d \n", *x + *y);
    printf("val 1 - val2 is : %d \n", *x - *y);
}

void swap_by_ref(int * a, int *b) {
    // int tmp = *a;
    // *a = *b;
    // *b = tmp;

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void store_in_int (int *a) {
    char *b = (char*) a;
    *(b+1) = 'a';
    *(b+2) = 'b';
    short c = 10;
    *(b+3) = c;
    printf("1 byte is: %c \n", *(b+1));
    printf("2 byte is: %c \n", *(b+2));
    printf("3-4 byte is: %d \n", *(b+3));
}
 
int main () {
    // int a = 1;
    // char b = 2;
    // double c = 3;

    // int * pta = &a;
    // char * ptb = &b;
    // double * ptc = &c;
    // print_addreses(pta, ptb, ptc);

    // printf("\n");

    // const int size = 5;
    // int arr[size];

    // scan_arr(size, arr);
    // print_arr(size, arr);

    // printf("\n");

    // int x = 4;
    // int * ptx = &x;
    // print_val_by_ref(ptx);

    // printf("\n");

    // int num = 10;
    // int num2 = 5;
    // int *pnum = &num;
    // int *pnum2 = &num2;
    // arithmetic_actions_by_ref(pnum,pnum2);


    // int mek = 20;
    // int erku = 30;
    // swap_by_ref(&mek, &erku);
    // printf("mek is : %d    erku is : %d", mek, erku);

    // int store = 0;
    // store_in_int(&store);

    char arr[5] = {1,2,3,4,5};
    printf("%p \n", arr);
    printf("%p \n", arr+1);
    printf("%p \n", &arr);
    // printf("%p \n", &arr + 2);

}