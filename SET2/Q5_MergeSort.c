#include <stdio.h>

void mergeSort(int arr[], int n) {

    int temp[n];

    // size = size of already sorted subarrays
    for (int size = 1; size < n; size *= 2) {

        for (int left = 0; left < n - 1; left += 2 * size) {

            int mid = left + size - 1;
            int right = left + 2 * size - 1;

            if (mid >= n - 1)
                continue;

            if (right >= n)
                right = n - 1;

            int i = left;
            int j = mid + 1;
            int k = left;

            // Merge two sorted parts
            while (i <= mid && j <= right) {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }

            while (i <= mid)
                temp[k++] = arr[i++];

            while (j <= right)
                temp[k++] = arr[j++];

            // Copy back
            for (i = left; i <= right; i++)
                arr[i] = temp[i];
        }
    }
}

int main() {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}