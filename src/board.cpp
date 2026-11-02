#include "board.hpp"

Board::Board() {
    // Initialize the board with empty spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = -1;
        }
    }
}

bool Board::setCell(int row, int col, int player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (board[row][col] != -1) {
            return false; // Cell is already occupied
        }
        // Set the cell to the player's value (0 or 1)
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Board::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == -1) {
                return false; // Found an empty cell
            }
        }
    }
    return true; // No empty cells found
}

bool Board::isCellEmpty(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return board[row][col] == -1; // Return true if the cell is empty
    }
    return false; // Invalid cell coordinates
}

bool Board::checkWin(int player) const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != player) {
                break;
            }
            if (j == 2) {
                return true; // Row win
            }
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][j] != player) {
                break;
            }
            if (i == 2) {
                return true; // Column win
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][i] != player) {
            break;
        }
        if (i == 2) {
            return true; // Diagonal win
        }
    }

    return false; // No win found
}
void Board::display() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                std::cout << "X";
            } else if (board[i][j] == 1) {
                std::cout << "O";
            } else {
                std::cout << " ";
            }
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}