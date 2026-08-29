#include <stdio.h>

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int n) {

    int stack[n];
    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {

        int high = stack[top--];
        int low = stack[top--];

        int p = partition(arr, low, high);

        // Right side
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }

        // Left side
        if (low < p - 1) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
    }
}