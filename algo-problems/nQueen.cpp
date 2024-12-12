#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Check column and diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve N-Queens
void solveNQueens(int n, int row, vector<int>& board, int& count) {
    if (row == n) {
        // All queens are placed
        ++count;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place queen at (row, col)
            solveNQueens(n, row + 1, board, count);
            // Backtrack: Remove the queen (not strictly necessary here)
        }
    }
}

// Function to find the total number of solutions for N-Queens
int totalNQueens(int n) {
    vector<int> board(n, -1); // Store the column position for each row
    int count = 0; // Count of solutions
    solveNQueens(n, 0, board, count);
    return count;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int solutions = totalNQueens(n);
    cout << "Number of solutions for " << n << "-Queens problem: " << solutions << endl;

    return 0;
}
