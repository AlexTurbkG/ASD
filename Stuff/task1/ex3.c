#include <stdio.h>

int func(int num, int rotation){
    int checker=1 << 31;    //makes only the first digit of the bin number 1
    for(int i = 0; i < rotation;i++){
        if(checker&num){        //if the first digit of "num" is "1" then the statement will be correct so we have to add 1 to the end, after moving it 1 place 
            num <<= 1;
            num += 1;

        }

        else num <<= 1;
    }

    return num;

}


int main(){
    printf("%d", func(2,1));
}

