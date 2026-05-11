/*
Algorithm NQueens(board, row, n)
Input: Chessboard of size n × n
Output: All possible arrangements of N queens

1. Start
2. If row == n
       Print the board configuration
       Return true
3. For each column col from 0 to n-1
4.     Check if placing queen at board[row][col] is safe
5.     If safe
6.         Place queen at board[row][col]
7.         Call NQueens(board, row + 1, n)
8.         Remove queen from board[row][col]   // Backtrack
9. End For
10. Stop

Function isSafe(board, row, col, n)
1. Check the same column in previous rows
2. Check upper left diagonal
3. Check upper right diagonal
4. If no queen attacks the position
       Return true
   Else
       Return false
*/

// C-CODE

#include <stdio.h>

#define MAX 20

int board[MAX][MAX];

int isSafe(int row, int col, int n)
{
    int i, j;

    // Check same column
    for(i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return 0;
    }

    // Check upper left diagonal
    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return 0;
    }

    // Check upper right diagonal
    for(i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

void printBoard(int n)
{
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int solveNQueens(int row, int n)
{
    int col;

    if(row == n)
    {
        printBoard(n);
        return 1;
    }

    for(col = 0; col < n; col++)
    {
        if(isSafe(row, col, n))
        {
            board[row][col] = 1;

            if(solveNQueens(row + 1, n))
                return 1;

            board[row][col] = 0; // Backtrack
        }
    }

    return 0;
}

int main()
{
    int n, i, j;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Initialize board
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if(!solveNQueens(0, n))
    {
        printf("No solution exists.\n");
    }

    return 0;
}

/*
OUTPUT
Enter the value of N: 4

Solution:
. Q . .
. . . Q
Q . . .
. . Q .
*/
