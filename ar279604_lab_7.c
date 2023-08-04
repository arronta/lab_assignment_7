#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[j]++;
                totalSwaps++;
            }
        }
    }
    printf("Total number of swaps: %d\n", totalSwaps);
}

int main() {
    int arr[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int* swaps = (int*)malloc(n * sizeof(int));
    if (swaps == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        swaps[i] = 0;
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n, swaps);

   

    printf("Swaps needed for each index:\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d: %d swaps\n", i, swaps[i]);
    }

    free(swaps);

    return 0;
}
