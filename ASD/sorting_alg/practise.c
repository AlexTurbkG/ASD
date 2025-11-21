#include <stdio.h>


void print_arr(int arr[], int size){
    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void merge(int arr[], int left, int mid, int right){
    int id1,id2,id3;
    int size1 = mid - left + 1;
    int size2 = right - mid;


    int left_arr[size1], right_arr[size2];

    for(id1 = 0;id1<size1;id1++){
        left_arr[id1] = arr[left + id1];
    }
    for(id2 = 0;id2<size2;id2++){
        right_arr[id2] = arr[mid + id2 + 1];
    }

    id1 = 0;
    id2 = 0;
    id3 = left;

    while(id1 < size1 && id2 < size2){
        if(left_arr[id1] <= right_arr[id2]){
            arr[id3] =  left_arr[id1];
            id1++;
        }
        else {
            arr[id3] = right_arr[id2];
            id2++;
        }
        id3++;
    }


    while(id1 < size1){
        arr[id3] = left_arr[id1];
        id1++;
        id3++;
    }

    while(id2 < size2){
        arr[id3] = right_arr[id2];
        id2++;
        id3++;
    }

}



void merge_sort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr,left,mid,right);
    }
}




int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr)/ sizeof(arr[0]);

    

    printf("Unsorted array: ");
    print_arr(arr, size);
    merge_sort(arr, 0, size - 1);
    printf("Sorted array: ");
    print_arr(arr, size);

    return 0;
}