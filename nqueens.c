#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int solutionCount = 0;

/* Check if queen placement is safe */
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

/* Print the board */
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

/* Solve N-Queens using backtracking */
void solveNQueens(int row, int n) {
    if (row == n) {
        solutionCount++;
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    solveNQueens(0, n);

    printf("Total solutions = %d\n", solutionCount);
    return 0;
}
