#include <stdio.h>



int get_bit(int n, int i){
    return (n>>i) & 1;
}



int main(){

    printf("%d ", get_bit(15, 7));

    return 0;
}