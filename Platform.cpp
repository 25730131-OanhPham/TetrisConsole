#include "Platform.h"

#ifdef _WIN32
   
    #include <conio.h>
    
    bool Input::isKeyPressed() {
        return _kbhit() != 0;
    }
    
    char Input::getChar() {
        return _getch();
    }
    
    void Input::setupConsole() {
       
    }
    
    void Input::restoreConsole() {
       
    }
    
    void Console::clear() {
        system("cls");
    }
    
    #include <windows.h>
    void Console::setCursorHome() {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Position = {0, 0};
        SetConsoleCursorPosition(hOut, Position);
    }

#else
  
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
    
        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        
        
        newSettings.c_lflag &= ~(ICANON | ECHO);
        newSettings.c_cc[VMIN] = 0;  
        newSettings.c_cc[VTIME] = 0;  
        
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
        
        std::cout << "\033[2J\033[H";
        std::cout.flush();
    }
    
    void Console::setCursorHome() {
        
        std::cout << "\033[H";
        std::cout.flush();
    }

#endif
