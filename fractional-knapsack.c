/*
Algorithm FractionalKnapsack
Input: Profits, weights of items, and capacity of knapsack
Output: Maximum profit

1. Start
2. Read number of items n
3. For each item:
       Read profit and weight
       Calculate ratio = profit / weight
4. Sort all items in decreasing order of ratio
5. Read knapsack capacity
6. Initialize totalProfit = 0
7. For each item:
       If item weight <= capacity:
            Add full item to knapsack
            totalProfit = totalProfit + profit
            capacity = capacity - weight
       Else:
            Add fractional part of item
            totalProfit = totalProfit + (profit * capacity / weight)
            Break
8. Print totalProfit
9. Stop
*/

// C-CODE

#include <stdio.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float capacity, totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for(i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);

        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    sortItems(items, n);

    for(i = 0; i < n; i++) {
        if(items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {
            totalProfit += items[i].profit * (capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

/*
OUTPUT
Enter number of items: 3
Enter profit and weight of item 1: 60 10
Enter profit and weight of item 2: 100 20
Enter profit and weight of item 3: 120 30
Enter capacity of knapsack: 50
Maximum profit = 240.00
*/
