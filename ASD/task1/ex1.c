#include <stdio.h>

int func(int num, int index){
    int h = 1;
    h <<=index;             //the number becomes as big as the index but with all 0s and one 1
    return h ^=num;         //xOr  with the original number makes it so only the 1 from "h" flips

}


int main(){
    printf("%d", func(10, 1));
}