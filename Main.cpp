#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 8

void printBoard(const std::vector<int>& board) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row] == col) {
                std::cout << "Q ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

bool isSafe(const std::vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueensLasVegas(std::vector<int>& board) {
    for (int row = 0; row < N; ++row) {
        std::vector<int> safePositions;
        for (int col = 0; col < N; ++col) {
            if (isSafe(board, row, col)) {
                safePositions.push_back(col);
            }
        }
        
        if (safePositions.empty()) {
            return false;
        }

        int chosenCol = safePositions[rand() % safePositions.size()];
        board[row] = chosenCol;
    }
    return true;
}

int main() {
    std::srand(std::time(0));

    std::vector<int> board(N, -1);
    bool solved = false;

    while (!solved) {
        solved = solveNQueensLasVegas(board);
    }

    printBoard(board);
    return 0;
}
