#pragma once

#include <iostream>

class Board {
public:
    Board();
    void display() const;
    bool setCell(int row, int col, int player);
    bool checkWin(int player) const;
private:
    int board[3][3];
};