#include <iostream>

#include "board.hpp"

int main() {
    Board board;
    bool is_player_1 = true; 
    
    while(true) {
        board.display();

        if (board.checkWin(0)) {
            std::cout << "Player 1 wins!" << std::endl;
            break;
        } else if (board.checkWin(1)) {
            std::cout << "Player 2 wins!" << std::endl;
            break;
        } else if (board.isFull()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        } else {
            int row, col, player;
            std::string player_name = is_player_1 ? "Player 1" : "Player 2";
            std::cout << "" << player_name << "'s turn. Enter row and column (0-2): ";
            std::cin >> row >> col;
            player = is_player_1 ? 0 : 1; // Player 1 is 0, Player 2 is 1

            if (board.isCellEmpty(row, col)) {
                board.setCell(row, col, player);
                is_player_1 = !is_player_1; // Switch turns
            } else {
                std::cout << "Invalid move. Try again." << std::endl;
            }
        }
    }
    
    return 0;
}