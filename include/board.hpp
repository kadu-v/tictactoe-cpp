#pragma once

#include <iostream>

class Board {
public:
    Board();
    void display() const;
private:
    bool board[3][3];
};