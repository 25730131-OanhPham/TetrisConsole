#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Block.h"

class Game {
private:
    Board board;
    Block currentBlock;
    bool isRunning;
    
public:
    Game();
    ~Game();
    
    void start();
    void update();
    void handleInput();
    void spawnNewBlock();
    bool isGameOver() const;
    
private:
    int getRandomBlockType() const;
};

#endif
