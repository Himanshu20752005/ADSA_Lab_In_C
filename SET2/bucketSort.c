#include <stdio.h>

void bucketSort(float arr[], int n) {

    float buckets[n][n];
    int count[n];

    // Initialize bucket counts
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {

            float temp = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = temp;
        }
    }

    // Combine buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {

    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}