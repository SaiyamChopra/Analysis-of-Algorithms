#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>
#define MAX 20
int board[MAX][MAX];
// Function to print the board
void printBoard(int N) {
	printf("\nSolution:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j])
				printf("Q  ");
			else
				printf(".  ");
		}
		printf("\n");
	}
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, int N) 
{
    // Check this column on the upper side
	for (int i = 0; i < row; i++)
		if (board[i][col])
			return false;

    // Check upper-left diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

    // Check upper-right diagonal
	for (int i = row, j = col; i >= 0 && j < N; i--, j++)
		if (board[i][j])
			return false;

	return true;
}

// Recursive function to solve the problem
bool solveNQueens(int row, int N) {
	if (row >= N)
		return true;
	for (int col = 0; col < N; col++) 
    {
		if (isSafe(row, col, N)) 
        {
			board[row][col] = 1;
			if (solveNQueens(row + 1, N))
				return true;
			board[row][col] = 0; // backtrack
		}
	}
	return false;
}

int main() {
	int N;
	printf("Enter the number of queens: ");
	scanf("%d", &N);

	if (N <= 0 || N > MAX) {
		printf("Please enter a valid number between 1 and %d.\n", MAX);
		return 1;
	}

// Initialize board to 0
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = 0;

	if (solveNQueens(0, N))
		printBoard(N);
	else
		printf("No solution exists for %d queens.\n", N);

	return 0;
}