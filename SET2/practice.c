#include<stdio.h>
void countSort(int arr[] ,int n){
    int max = arr[0];
    for(int i = 1 ;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int count[max+1];

    for(int i = 0 ;i<max+1 ;i++){
        count[i] = 0;
    }

    for(int i = 0 ;i<n ;i++){
        count[arr[i]]++;
    }

    int prefixsum = count[0];
    for(int i = 1 ;i<max+1 ;i++){
        prefixsum += count[i];
        count[i] = prefixsum;
    }
    
    int ans[n];
    for(int i = n-1 ;i>=0 ;i--){
        ans[--count[arr[i]]] = arr[i];
    }

    for(int i = 0 ;i<n;i++){
        arr[i] = ans[i];
    }

}

int main(){
    int arr[] = {9,8,7,5,4,3,2,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr,n);

    for(int i = 0 ;i< n ; i++){
        printf("%d ",arr[i]);
       }
    return 0;
}