#include "Game.h"
#include "Platform.h"
#include <cstdlib>
#include <ctime>
#include <thread>

Game::Game() 
    : currentBlock(rand() % 7, 5, 0), isRunning(true) {
    srand(time(0));
    board.init();
    Input::setupConsole();
    // lần rơi cuối là hiện tại
    lastFallTime = chrono::steady_clock::now();
}

Game::~Game() {
    Input::restoreConsole();
}

int Game::getRandomBlockType() const {
    return rand() % 7;
}

void Game::spawnNewBlock() {
    currentBlock.setPosition(5, 0);
    currentBlock = Block(getRandomBlockType(), 5, 0);
}

void Game::handleInput() {
    while (Input::isKeyPressed()) {
        char c = Input::getChar();
        if (c == 'w' || c == 'W') {
            Block rotatedBlock = currentBlock;
            rotatedBlock.rotate();
            if (board.canMove(rotatedBlock, 0, 0))
                currentBlock.rotate();
        }
        if ((c == 'a' || c == 'A') && board.canMove(currentBlock, -1, 0)) 
            currentBlock.moveX(-1);
        if ((c == 'd' || c == 'D') && board.canMove(currentBlock, 1, 0)) 
            currentBlock.moveX(1);
        if ((c == 'x' || c == 'X') && board.canMove(currentBlock, 0, 1)) 
            currentBlock.moveY(1);
        if ((c == 'q' || c == 'Q')) 
            isRunning = false;
    }
}

void Game::update() {
    // Remove old block from board
    board.removeBlock(currentBlock);
    
    // Handle input (key board)
    handleInput();
    auto now = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastFallTime).count();
    if (elapsed >= 500)
    {
        if (board.canMove(currentBlock, 0, 1)) {
        currentBlock.moveY(1);
        } else {
            // Place block and spawn new one
            board.placeBlock(currentBlock);
            board.removeLine();
            spawnNewBlock();
        }
        lastFallTime = now;
    }

    // Apply gravity
    
    
    // Place current block on board
    board.placeBlock(currentBlock);
    
    // Draw
    board.draw();
    
    // Game loop speed
    this_thread::sleep_for(chrono::milliseconds(30));
}

void Game::start() {
    board.draw();
    
    while (isRunning) {
        update();
    }
}

bool Game::isGameOver() const {
    return !isRunning;
}
