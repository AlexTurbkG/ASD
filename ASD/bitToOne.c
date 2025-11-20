#include <stdio.h>


int bitToOne(int n, int i){
    n = n | (1 << i);
    return n;
}



int main(){
    printf("%d ", bitToOne(10, 4));

    return 0;
}