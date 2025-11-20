#include <stdio.h>


int digits(int n){
    if(n == 0) return 0;
    return 1 + digits(n / 10);
}




int main(){

    printf("%d ", digits(100));
    return 0;
}