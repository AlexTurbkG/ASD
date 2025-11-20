#include <stdio.h>

int func(int a, int b){
    a>>=4;
    a<<=4;  //removes the last 4 digits of the bin number
    return a|=b;

}


int main(){

    printf("%d", func(100, 7));
    return 0;
}