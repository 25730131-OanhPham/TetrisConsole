#include "Game.h"
#include "Platform.h"

int main() {
    srand(time(0));
    // Setup console for all platforms
    Console::setupEncoding();
    
    Game game;
    game.start();
    
    return 0;
}
