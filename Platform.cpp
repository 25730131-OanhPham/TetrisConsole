#include "Platform.h"

#ifdef _WIN32
    // Windows implementation
    #include <conio.h>
    
    bool Input::isKeyPressed() {
        return _kbhit() != 0;
    }
    
    char Input::getChar() {
        return _getch();
    }
    
    void Input::setupConsole() {
        // Windows console already supports raw mode
    }
    
    void Input::restoreConsole() {
        // Nothing to restore on Windows
    }
    
    void Console::clear() {
        system("cls");
    }
    
    void Console::setCursorHome() {
        system("cls");
    }

#else
    // Unix/Linux/macOS implementation
    #include <termios.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <cstring>
    #include <fcntl.h>
    
    static struct termios oldSettings, newSettings;
    static int oldFlags;
    
    bool Input::isKeyPressed() {
        struct timeval tv = {0, 0};
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        return select(1, &readfds, nullptr, nullptr, &tv) > 0;
    }
    
    char Input::getChar() {
        char buf = 0;
        if (read(STDIN_FILENO, &buf, 1) > 0) {
            return buf;
        }
        return 0;
    }
    
    void Input::setupConsole() {
        // Save old settings
        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        
        // Disable canonical mode and echo
        newSettings.c_lflag &= ~(ICANON | ECHO);
        newSettings.c_cc[VMIN] = 0;   // Non-blocking
        newSettings.c_cc[VTIME] = 0;  // No timeout
        
        // Save old stdin flags
        oldFlags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldFlags | O_NONBLOCK);
        
        tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    }
    
    void Input::restoreConsole() {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
        fcntl(STDIN_FILENO, F_SETFL, oldFlags);
    }
    
    void Console::clear() {
        // ANSI escape code for clear screen
        std::cout << "\033[2J\033[H";
        std::cout.flush();
    }
    
    void Console::setCursorHome() {
        // ANSI escape code for cursor home
        std::cout << "\033[H";
        std::cout.flush();
    }

#endif
