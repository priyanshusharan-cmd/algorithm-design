/*
Algorithm MergeSort(arr, l, r)
Input: An array 'arr', left index 'l', and right index 'r'
Output: A sorted array

1. If l < r:
2.     Calculate the mid point: m = l + (r - l) / 2
3.     Call MergeSort(arr, l, m)      // Sort first half
4.     Call MergeSort(arr, m + 1, r)  // Sort second half
5.     Call Merge(arr, l, m, r)       // Merge the sorted halves


Algorithm Merge(arr, l, m, r)
Input: An array 'arr', left index 'l', middle index 'm', and right index 'r'

1. Calculate sizes of two subarrays: n1 = m - l + 1, n2 = r - m
2. Create temporary arrays L[n1] and R[n2]
3. Copy data to temporary arrays L[] and R[]
4. Initialize indices i = 0, j = 0, k = l
5. While i < n1 and j < n2:
6.     If L[i] <= R[j]:
7.         arr[k] = L[i]
8.         i = i + 1
9.     Else:
10.        arr[k] = R[j]
11.        j = j + 1
12.    k = k + 1
13. Copy any remaining elements of L[] into arr[]
14. Copy any remaining elements of R[] into arr[]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    // Note: Variable Length Arrays (VLA) are supported in C99
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts arr[l..r] using merge()
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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

        // Only print the array if N is small, otherwise it floods the terminal
        if (n <= 20) {
            printf("\nOriginal Array: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        // Record the starting time
        clock_t start = clock();

        // Perform merge sort
        mergeSort(arr, 0, n - 1);

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
