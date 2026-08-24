#include<stdio.h>

void swap(int arr[] , int j , int k){
             int temp = arr[j];
             arr[j] = arr[k];
             arr[k] = temp;
}

void bubbleSort(int arr[] , int n){
    for(int i = 0 ;i<n-1 ;i++){
        for(int j = 0 ;j<n-1-i ;j++){
           if(arr[j] > arr[j+1]){
            swap(arr,j,j+1);
            
           }
        }
    }
}


int main(){
    int arr[] = {9,8,7,5,4,3,2,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);

    for(int i = 0 ;i< n ; i++){
        printf("%d ",arr[i]);
       }
    return 0;
}