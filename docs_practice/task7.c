#include <stdio.h>
#include <stdbool.h>

// 7. https://leetcode.com/problems/valid-anagram/


int my_strlen (char *s) {
    int count = 0;
    while (*s){
        count++;
        s++;
    }
    return count;
}

bool isAnagram(char* s, char* t) {
    if (s == NULL || t == NULL) return false;
    if (my_strlen(s) != my_strlen(t)) return false;
    
    int arr[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }

    for (int i = 0 ; i < 26; i++ ) {
        if (arr[i]) return false;
    }
    return true;
}


int main () {
    bool res = isAnagram("anagram", "nagaram");
    printf("%d",res);
}