#include <stdio.h>
#include <stdbool.h>

void swap(int *arr, int i, int pivot){
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
}


void partition(int *arr, int size, int pivot){

    while(pivot < size){
        for(int i = 0; i < size; i++){
            if(arr[i] > arr[pivot]){
                swap(arr, i , pivot);
            }
        }
        pivot++;

    }
}



void quick_sort(int *arr, int start, int end){
    if(end <= start) return;
    int pivot = (end - start) / 2;

    partition(arr, end - start, pivot); 


    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot+1, end);
}

int main(){
    int arr[9] = {1, 3, 67, 67, 0, -6, -7, 5, 53};

    for(int i = 0;i < 9;i++){
        partition(arr, 9 , i);
    }

    for(int i = 0 ;i < 9;i++){
        printf("%d ", arr[i]);
    }
}