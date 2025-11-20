#include <stdio.h>
#include <string.h>


void reverser(char *str, int id1, int id2, char *reversed){
    if(id2 < id1) return;
    reversed[id2] = str[id1];
    reversed[id1] = str[id2];
    reverser(str, id1 + 1, id2 - 1, reversed);
}


int main(){
    char *str = "MAZNA";
    int size = strlen(str);
    char reversed[size];
    reversed[size] = '\0';
    reverser(str, 0, size - 1, reversed);
    
    printf("%s\n", reversed);
    
}