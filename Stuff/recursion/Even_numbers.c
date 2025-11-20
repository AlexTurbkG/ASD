#include <stdio.h>

int count_even(int *arr,int size){
    if(size == 0){
        return 0;
    }
    if(*arr%2 == 1){
        return 0 + count_even(arr+1,size-1);
    }
    else{
        return 1 + count_even(arr+1,size-1);
    }

}

int main(){
    int arr[5] = {2,4,6,3,5};
    int result = count_even(arr,5);
    printf("%d",result);

    return 0;
}