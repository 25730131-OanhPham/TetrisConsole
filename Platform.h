#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>

// Cross-platform keyboard input
class Input {
public:
    // Check if a key is pressed 
    static bool isKeyPressed();
    
    // Get a single character input 
    static char getChar();
    
    // Setup console for raw input
    static void setupConsole();
    
    // Restore console to normal mode
    static void restoreConsole();
};

// Cross-platform console utilities
class Console {
public:
    // Clear the entire screen
    static void clear();
    
    // Set cursor to home position
    static void setCursorHome();
    
    // Setup console encoding (UTF-8 support)
    static void setupEncoding();
};

#endif
