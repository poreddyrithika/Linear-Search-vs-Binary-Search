#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    // The array sizes can be modified as needed to test and compare
    // the performance of Linear Search and Binary Search for different input sizes.
    int sizes[] = {1000, 5000, 10000, 50000, 100000}; 
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("Size\tLinear Search (ms)\tBinary Search (ms)\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));

        // Generate sorted random numbers
        arr[0] = rand() % 10;
        for (int j = 1; j < n; j++) {
            arr[j] = arr[j - 1] + rand() % (n * 10);
        }

        int target = arr[n - 1];

        // Linear Search timing
        clock_t start = clock();
        linear_search(arr, n, target);
        clock_t end = clock();
        double linear_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

        // Binary Search timing
        start = clock();
        binary_search(arr, n, target);
        end = clock();
        double binary_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

        printf("%d\t%.5f\t\t%.5f\n", n, linear_time, binary_time);

        free(arr);
    }

    return 0;
}
