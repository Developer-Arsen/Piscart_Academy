#include <stdio.h>
// 5.Գրեք «findIndex» անունով ֆունկցիա, որն ընդունում է ամբողջ թվերի զանգվածը, զանգվածի չափը և ֆունկցիայի ցուցիչը։ «findIndex» ֆունկցիան պետք է վերադարձնի զանգվածի առաջին տարրի ինդեքսը, որն անցնում է տրամադրված ֆունկցիայի կատարած թեստը։ Եթե ​​նման տարր չի գտնվել, վերադարձրեք -1:
// int findIndex(int arr*, int size, int (*testFunc)(int));

int is_prime (int n) {
    if (n == 0 || n == 1 || n == 2 ) return 1;

    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int findIndex(int * arr, const int size, int (*testFunc)(int)) {
    for (int i = 0; i < size; i++) {
        if (testFunc(arr[i])) return i;
    }
    return -1;    
}


int main () {
    const int size = 5;
    int arr[] = {10,6,8,10,5};
    printf("%d", findIndex(arr, size, is_prime));

}