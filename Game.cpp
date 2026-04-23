#include "Game.h"
#include "Platform.h"
#include <cstdlib>
#include <ctime>
#include <thread>

Game::Game() 
    : currentBlock(rand() % 7, 5, 0), isRunning(true), fallSpeed(500) {
    srand(time(0));
    board.init();
    Input::setupConsole();

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
    
    board.removeBlock(currentBlock);

    handleInput();
    auto now = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastFallTime).count();
    if (elapsed >= fallSpeed)
    {
        if (board.canMove(currentBlock, 0, 1)) {
            currentBlock.moveY(1);
        } else {

            board.placeBlock(currentBlock);
            int linesCleared = board.removeLine();
            if (linesCleared > 0) {
                
                fallSpeed -= linesCleared * 50; 
              
                if (fallSpeed < 50) {
                    fallSpeed = 50;
                }
            }
            spawnNewBlock();
        }
        lastFallTime = now;
    }
 
    board.placeBlock(currentBlock);
    
   
    board.draw();
    

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
