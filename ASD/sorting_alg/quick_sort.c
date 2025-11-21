#include <stdio.h>

void print_arr(int arr[], int size){
    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}


int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int id1 = low - 1;

    for(int id2 = low; id2<=high;id2++){
        if(arr[id2] < pivot){
            id1++;
            swap(&arr[id1], &arr[id2]);
        }
    }
    swap(&arr[id1 + 1], &arr[high]);
    return id1 + 1;
}


int quick_sort(int arr[], int low, int high){
    if(low < high){
        int pivId = partition(arr,low,high);

        quick_sort(arr, low, pivId - 1);
        quick_sort(arr, pivId + 1, high);

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