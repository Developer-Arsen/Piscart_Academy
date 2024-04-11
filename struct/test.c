#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// enum Roles {
//     SHEF, MATUCOX, BOMJ
// };

// typedef struct Person {
//     char name[10];
//     enum Roles role;
//     int age;
// } Person;

// void foo (Person *obj) {
//     switch (obj->role)
//     {
//     case SHEF:
//         printf("shefu normali");
//         break;
//     case MATUCOX:
//         printf("hyly ashxtelu tex ka");
//         break;
//     default:
//         printf("SHAT VATA");
//         break;
//     }
// }

struct A {
    int* a;
} typedef A;

union test 
{
    int* a;
    int arr[100];
};


int main () {
    union test obj1;

    // obj1 = (struct A){5};
    // A * ptr = &obj1;
    // ptr -> a = 5;
    // (*ptr).a = 5;
    obj1.a = (int*) malloc(1000);


    *(obj1).a = 4;
    (*(obj1).a)++;
    *obj1.a = 8;
    // obj1.obj.a = 5;
    printf("%d\n", *obj1.a);
    printf("%ld", sizeof(obj1));

    // Person obj = {"de hima", SHEF, 500};
    // foo(&obj);
    // str = &item;
    // str->a = 5;
    // str->a = 5;
    // printf("%d", str->a);
    // char arr[55];
    // fgets(arr, 55, stdin);
    // puts(arr);

}