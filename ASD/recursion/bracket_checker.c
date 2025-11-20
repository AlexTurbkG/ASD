#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int bracket_checker(char *str, int id1, int id2, int max, int step){
    if(id1 == id2) return;
    
    
}


int main(){
    char *str = "[(){}]";
    int size = strlen(str);
    printf("Are the brackets true: %s\n", bracket_checker(str, 0, size-1, size-1, 1) ? "YES" : "NO");

}