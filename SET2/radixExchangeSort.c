#include <stdio.h>

void radixExchangeSort(int arr[], int n) {
    int stack[n];
    int top = -1;

    // Find the highest bit
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int bit = 0;

    while ((max >> bit) > 1)
        bit++;

    stack[++top] = 0;
    stack[++top] = n - 1;
    stack[++top] = bit;

    while (top >= 0) {

        int b = stack[top--];
        int right = stack[top--];
        int left = stack[top--];

        if (left >= right || b < 0)
            continue;

        int i = left;
        int j = right;

        // Partition based on current bit
        while (i <= j) {

            while (i <= j && ((arr[i] >> b) & 1) == 0)
                i++;

            while (i <= j && ((arr[j] >> b) & 1) == 1)
                j--;

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        // Process right part
        if (i < right) {
            stack[++top] = i;
            stack[++top] = right;
            stack[++top] = b - 1;
        }

        // Process left part
        if (left < j) {
            stack[++top] = left;
            stack[++top] = j;
            stack[++top] = b - 1;
        }
    }
}

int main() {
    int arr[] = {10, 7, 3, 12, 5, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixExchangeSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}