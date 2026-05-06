/*
Algorithm QuickSort(arr, low, high)
Input: An array 'arr', starting index 'low', and ending index 'high'
Output: A sorted array

1. If low < high:
2.     Find the partition index: pi = Partition(arr, low, high)
3.     Call QuickSort(arr, low, pi - 1)  // Sort elements before pivot
4.     Call QuickSort(arr, pi + 1, high) // Sort elements after pivot


Algorithm Partition(arr, low, high)
Input: An array 'arr', starting index 'low', and ending index 'high'
Output: The correct index of the pivot element

1. Select the rightmost element as pivot: pivot = arr[high]
2. Initialize index of smaller element: i = low - 1
3. For j from low to high - 1:
4.     If arr[j] < pivot:
5.         Increment i: i = i + 1
6.         Swap arr[i] and arr[j]
7. Swap arr[i + 1] and arr[high] (Places pivot in correct position)
8. Return i + 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utility function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function that takes the last element as pivot, places
// the pivot element at its correct position in sorted array, and
// places all smaller (smaller than pivot) to left of pivot and all
// greater elements to right of pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Main function that implements QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    do {
        printf("\nEnter the number of elements (N) to sort: ");
        scanf("%d", &n);

        // Dynamically allocate memory for the array
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Fill array with random integers
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000; 
        }

        // Only print the array if N is small
        if (n <= 20) {
            printf("\nOriginal Array: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        // Record the starting time
        clock_t start = clock();

        // Perform quick sort
        quickSort(arr, 0, n - 1);

        // Record the ending time
        clock_t end = clock();

        // Calculate time taken in seconds
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        if (n <= 20) {
            printf("Sorted Array:   ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        // Print the time taken
        printf("\n--> Time taken to sort %d elements: %f seconds <--\n", n, time_taken);

        // Free the dynamically allocated memory
        free(arr);

        // Ask the user if they want to test another value of N
        printf("\nDo you want to test another value of N? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program.\n");
    return 0;
}
