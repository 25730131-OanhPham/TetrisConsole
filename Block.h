#ifndef BLOCK_H
#define BLOCK_H

class Block {
private:
    static const char blocks[16][4][4];
    int blockType;
    int rotation;
    int x, y;

public:
    Block(int type = 0, int startX = 5, int startY = 0);
    
    // Getters
    int getX() const 
    { 
        return x; 
    }
    int getY() const 
    { 
        return y; 
    }
    int getType() const 
    { 
        return blockType;
    }
    char getCell(int row, int col) const;
    
    // Setters
    void setPosition(int newX, int newY) 
    { 
        x = newX; 
        y = newY; 
    }
    void moveX(int dx) 
    { 
        x += dx; 
    }
    void moveY(int dy) 
    { 
        y += dy; 
    }
    
    // Rotation
    void rotate() 
    {
        if (blockType != 1)
            rotation = (rotation + 1) & 3;
    }
};

#endif
