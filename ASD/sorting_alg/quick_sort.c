#include <stdio.h>

void print_arr(int arr[], int size){
    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){


        //finds the first element bigger than the pivot from the start
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }

        //finds the first element smaller than the pivot from the end
        while(arr[j] >= pivot && j >= low + 1){
            j--;
        }

        if(i < j){
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int partId = partition(arr, low, high);


        quick_sort(arr, low, partId - 1);
        quick_sort(arr, partId + 1, high);
    }
}


int main(){
    int arr[] = { 4, 2, 5, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    print_arr(arr, size);
    quick_sort(arr,0, size - 1);
    printf("Sorted array: ");
    print_arr(arr, size);
}