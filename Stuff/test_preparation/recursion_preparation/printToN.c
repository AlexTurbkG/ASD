#include <stdio.h>

void printToN(int n){
    static int i = 0;
    if(i == n) return ;
    i = i + 1;
    printf("%d ", i);

    return printToN(n);
}


int main(){
    printToN(5);
    return 0;
}

