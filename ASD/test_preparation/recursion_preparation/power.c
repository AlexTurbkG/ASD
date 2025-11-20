#include <stdio.h>

int power(int i, int n){
    if(!n) return 1;
    return i * power(i, n-1);
}


int main(){
    printf("%d ", power(2, 3));

    return 0;
}