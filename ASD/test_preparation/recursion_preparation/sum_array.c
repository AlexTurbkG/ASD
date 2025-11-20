#include <stdio.h>

int sum(int arr[], int n){
    if(n == 0) return 1;
    return arr[n-1] + sum(arr, n-1);
}


