/*
Algorithm JohnsonTrotter(n)

Input: Integer n
Output: All permutations of numbers from 1 to n

1. Initialize array perm[] with values 1 to n
2. Initialize all directions as LEFT
3. Print the current permutation

4. Repeat
      a. Find the largest mobile element
         - An element is mobile if:
           i. It can move in its current direction
           ii. It is greater than the adjacent element

      b. If no mobile element exists
            Stop

      c. Swap the mobile element with the adjacent element
         in its current direction

      d. Reverse the direction of all elements
         greater than the mobile element

      e. Print the new permutation

5. End
*/

//C- CODE

#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to find position of largest mobile element
int getLargestMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {

        // Check LEFT direction
        if (dir[i] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        // Check RIGHT direction
        if (dir[i] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Johnson Trotter Algorithm
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {

        int mobileIndex = getLargestMobile(perm, dir, n);

        // No mobile element
        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + dir[mobileIndex];

        // Swap elements
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Swap directions
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        int mobile = perm[swapIndex];

        // Reverse directions of larger elements
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Permutations are:\n");

    johnsonTrotter(n);

    return 0;
}

/*
OUTPUT
Enter number of elements: 3
Permutations are:
1 2 3
1 3 2
3 1 2
3 2 1
2 3 1
2 1 3
*/
