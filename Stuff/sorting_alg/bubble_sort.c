#include <stdio.h>

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(int arr[], int size){
    for(int i = 0;i < size - 1;i++){
        for(int j=0;j < size - i - 1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

int main(){
    int arr[] = {5,2,3,6,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, size);

    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}