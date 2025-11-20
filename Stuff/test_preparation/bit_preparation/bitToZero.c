#include <stdio.h>


int bitToZero(int n, int i){
    n = n & ~(1<<i);
    return n;
}




int main(){
    printf("%d", bitToZero(10, 1));

    return 0;
}