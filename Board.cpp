#include "Board.h"
#include "Platform.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Board::Board() {}

void Board::init() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) 
                board[i][j] = '#';
            else 
                board[i][j] = ' ';
}

void Board::draw() const {
    Console::clear();
    for (int i = 0; i < HEIGHT; i++, cout << endl)
        for (int j = 0; j < WIDTH; j++) 
        {
            if (board[i][j] == '*')
            {
                cout << u8"██";
            }
            else if (board[i][j] == '#') 
            {
                cout << "##";
            }
            else
            {
                cout << board[i][j] << board[i][j];
            }
        }
            
}

bool Board::canMove(const Block& block, int dx, int dy) const {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block.getCell(i, j) != ' ') {
                int xt = block.getX() + j + dx;
                int yt = block.getY() + i + dy;
                
                if (xt < 1 || xt >= WIDTH - 1 || yt >= HEIGHT - 1) 
                    return false;
                if (board[yt][xt] != ' ') 
                    return false;
            }
        }
    }
    return true;
}

void Board::placeBlock(const Block& block) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block.getCell(i, j) != ' ') {
                int posY = block.getY() + i;
                int posX = block.getX() + j;
                if (posY >= 0 && posY < HEIGHT && posX >= 0 && posX < WIDTH) {
                    board[posY][posX] = block.getCell(i, j);
                }
            }
        }
    }
}

void Board::removeBlock(const Block& block) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block.getCell(i, j) != ' ') {
                int posY = block.getY() + i;
                int posX = block.getX() + j;
                if (posY >= 0 && posY < HEIGHT && posX >= 0 && posX < WIDTH) {
                    board[posY][posX] = ' ';
                }
            }
        }
    }
}

bool Board::isLineFull(int row) const {
    for (int j = 1; j < WIDTH - 1; j++)
        if (board[row][j] == ' ') 
            return false;
    return true;
}

void Board::removeLine() {
    // Diem viet ham o day nha em
}

char Board::getCell(int row, int col) const {
    if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) 
        return ' ';
    return board[row][col];
}
