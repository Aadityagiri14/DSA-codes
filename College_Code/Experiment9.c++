#include <iostream>
#include <vector>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; ++i)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;
    return true;
}

void solveNQUtil(int board[N][N], int col, std::vector<std::vector<int>>& solutions) {
    if (col >= N) {
        std::vector<int> solution;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                solution.push_back(board[i][j]);
            }
        }
        solutions.push_back(solution);
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, solutions);
            board[i][col] = 0;
        }
    }
}

void solveNQ() {
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};
    std::vector<std::vector<int>> solutions;
    solveNQUtil(board, 0, solutions);
    if (solutions.empty()) {
        std::cout << "No solutions found." << std::endl;
    } else {
        std::cout << "Total solutions: " << solutions.size() << std::endl;
        for (const auto& solution : solutions) {
            for (int i = 0; i < N * N; ++i) {
                std::cout << solution[i] << " ";
                if ((i + 1) % N == 0)
                    std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    solveNQ();
    return 0;
}
