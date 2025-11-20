#include <stdio.h>


int bitFlip(int n, int i){
    n = n ^ (1<<i);
}

int main(){

    printf("%d ", bitFlip(10,3));
    return 0;
}

