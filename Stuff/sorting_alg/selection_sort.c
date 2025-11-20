#include <stdio.h>

void print_arr(int arr[], int size){
    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int size){
    for(int i = 0;i < size;i++){

        int min_id = i;
        for(int j = i + 1;j < size;j++){
            if(arr[j] < arr[min_id]){
                min_id = j;
            }
        }

        swap(arr, min_id, i);
    }
}


int main(){

    int arr[] = {64,25,12,22,11};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    print_arr(arr, size);
    selection_sort(arr,size);
    printf("Sorted array: ");
    print_arr(arr, size);

}