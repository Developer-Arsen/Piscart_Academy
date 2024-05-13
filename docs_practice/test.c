#include <stdio.h>
#include <string.h>

int my_strlen(char* src) {
    if (src == NULL) return 0;

    int index = 0;
    while (src[index])
    {
        index++;
    }
    return index++;
}

int main () {
    char * str = "hello world";

    int size = my_strlen(str);
    int sum = 0;
    for (size_t i = size ; i != 0; i--) 
    {
        printf("%c", str[i]);
        printf("%d \n", str[i] == ' ' && sum > 0);
        
        if (str[i] == ' ' && sum > 0) break;
        if (str[i] == ' ') continue;
        sum++;
    }
    
    printf("%d \n" , sum);
}