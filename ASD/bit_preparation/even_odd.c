#include <stdio.h>

int even_odd(int n){
    if(n & 1) return 0;
    else return 1;
}



int main(){

    printf("%s", (even_odd(1) ? "Even": "Odd"));
    return 0;
}