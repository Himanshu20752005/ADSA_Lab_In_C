#include<stdio.h>

int main(){
    int arr[] = {9,8,7,5,4,3,2,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);

    for(int i = 0 ;i< n ; i++){
        printf("%d ",arr[i]);
       }
    return 0;
}