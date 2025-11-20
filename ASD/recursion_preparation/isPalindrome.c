#include <stdio.h>

int get_size(char *s){
    if(*s != '\0'){
        return 1 + get_size(s + 1);
    }
    return 0;
}


int isPalindrome(char *s, int left, int right){
    if(right < left) return 1;
    if(s[left] == s[right]){
        right--;
        left++;
        return isPalindrome(s, left, right);
    }
    return 0;
}


int main(){
    char *str = "mazam";

    printf("%d ", isPalindrome(str, 0, get_size(str)-1));
    return 0;
}