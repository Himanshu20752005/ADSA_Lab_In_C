#include <stdio.h>

void addressCalculationSort(int arr[], int n) {
    int bucket[10][n];
    int count[10] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;   // address calculation

        if (index > 9)
            index = 9;

        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < count[i]; j++) {
            int temp = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > temp) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = temp;
        }
    }

    // Merge buckets
    int index = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}