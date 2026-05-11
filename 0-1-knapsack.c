/*
Algorithm Knapsack(W, wt[], val[], n)

Input:
    W      → Capacity of knapsack
    wt[]   → Array of item weights
    val[]  → Array of item values
    n      → Number of items

Output:
    Maximum profit that can be obtained

1. Create a table K[n+1][W+1]

2. For i from 0 to n:
       For w from 0 to W:

3.        If i == 0 OR w == 0:
              K[i][w] = 0

4.        Else if wt[i-1] <= w:
              K[i][w] = maximum(
                              val[i-1] + K[i-1][w - wt[i-1]],
                              K[i-1][w]
                           )

5.        Else:
              K[i][w] = K[i-1][w]

6. Return K[n][W]
*/

// C-CODE

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if(wt[i - 1] <= w)
            {
                K[i][w] = max(
                    val[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]
                );
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main()
{
    int n, W, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);

    printf("Maximum Profit = %d\n", result);

    return 0;
}

/*
Enter number of items: 3
Enter weights of items:
10 20 30
Enter values of items:
60 100 120
Enter capacity of knapsack: 50
Maximum Profit = 220
*/
