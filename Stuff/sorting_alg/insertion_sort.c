#include <stdio.h>

void insertion_sort(int arr[], int size){
    for(int i = 1;i<size;i++){
        int key = arr[i];
        int prev = i - 1;

        for( ;prev>=0 && arr[prev] > key; prev--){
            arr[prev + 1] = arr[prev];
        }
        arr[prev + 1] = key;
    }
}

void printf_arr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    printf_arr(arr, size);
    return 0;
}