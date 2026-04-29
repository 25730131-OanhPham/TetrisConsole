#include "Game.h"
#include "Platform.h"

int main() {
    // Setup console for all platforms
    Console::setupEncoding();
    
    Game game;
    game.start();
    
    return 0;
}
