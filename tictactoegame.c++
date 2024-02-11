#include <iostream>
#include <vector>
#include <string>

// Function to print the Tic Tac Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));

    bool player1Turn = true;
    int movesLeft = 9;

    std::cout << "Welcome to Tic Tac Toe!\n";

    while (movesLeft > 0) {
        // Print the current board
        std::cout << "Current Board:\n";
        printBoard(board);

        // Determine current player
        char currentPlayerSymbol = (player1Turn) ? 'X' : 'O';
        std::cout << "Player " << currentPlayerSymbol << ", enter your move (row and column): ";
        
        int row, col;
        std::cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
            std::cout << "Invalid move. Please try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayerSymbol;
        --movesLeft;

        // Check for win
        if (checkWin(board, currentPlayerSymbol)) {
            std::cout << "Player " << currentPlayerSymbol << " wins!\n";
            printBoard(board);
            break;
        }

        // Switch player
        player1Turn = !player1Turn;
    }

    if (movesLeft == 0) {
        std::cout << "It's a draw!\n";
    }
 return 0;
}
