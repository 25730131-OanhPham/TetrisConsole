#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board {
private:
    static const int HEIGHT = 20;
    static const int WIDTH = 10;
    char board[HEIGHT][WIDTH];

public:
    Board();
    
  
    void init();
    void draw() const;
    

    bool canMove(const Block& block, int dx, int dy) const;
    void placeBlock(const Block& block);
    void removeBlock(const Block& block);
    int removeLine();
    

    int getHeight() const { return HEIGHT; }
    int getWidth() const { return WIDTH; }
    char getCell(int row, int col) const;
    bool isLineFull(int row) const;
};

#endif
