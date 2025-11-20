#include <stdio.h>

int get_size(char *str){
    if(*str != '\0'){
        return 1 + get_size(str + 1);
    }
    return 0;
}


char is_palindrome(char* str, int id1, int id2){
    if(id2 <= id1) return 1;
    if(str[id1] == str[id2]){
        id1++;
        id2--;
        return is_palindrome(str, id1, id2);
    }
    return 0;
}

int main(){
    char *str = "omo";
    printf("Is palindorme?: %s\n", is_palindrome(str, 0, get_size(str)-1) ? "Yes" : "No");
}