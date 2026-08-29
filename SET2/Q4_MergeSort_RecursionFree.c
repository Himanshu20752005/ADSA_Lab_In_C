#include <stdio.h>

typedef struct {
    int left;
    int right;
} Range;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int n) {

    Range stack[n];
    int top = -1;

    // Push the complete array
    stack[++top].left = 0;
    stack[top].right = n - 1;

    while (top >= 0) {

        // Pop a range
        int left = stack[top].left;
        int right = stack[top].right;
        top--;

        if (left >= right)
            continue;

        int mid = left + (right - left) / 2;

        // Push right half
        stack[++top].left = mid + 1;
        stack[top].right = right;

        // Push left half
        stack[++top].left = left;
        stack[top].right = mid;

        // Merge after both halves are processed
        merge(arr, left, mid, right);
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