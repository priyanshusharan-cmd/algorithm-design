/*
Algorithm HeapSort(arr, n)
Input: An array 'arr' of size n
Output: Array sorted in ascending order

1. Build a max heap from the array:
       For i = n/2 - 1 down to 0:
           Heapify(arr, n, i)

2. Perform heap sort:
       For i = n - 1 down to 1:
           Swap arr[0] and arr[i]
           Heapify(arr, i, 0)

3. End


Algorithm Heapify(arr, n, i)

1. Set largest = i
2. Set left = 2*i + 1
3. Set right = 2*i + 2

4. If left < n and arr[left] > arr[largest]:
       largest = left

5. If right < n and arr[right] > arr[largest]:
       largest = right

6. If largest != i:
       Swap arr[i] and arr[largest]
       Heapify(arr, n, largest)

7. End
*/

//C-CODE

#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    // Build max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, i;
    int arr[100];

    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();

    heapSort(arr, n);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(arr, n);

    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}

/*
OUTPUT
Enter number of elements: 6
Enter elements:
45 12 89 23 7 56

Sorted array:
7 12 23 45 56 89

Time taken: 0.000002 seconds
*/
