# 🎮 Tetris Console Game

A classic Tetris game implemented in C++ with Object-Oriented design and cross-platform support (Windows, macOS, Linux).

## 🚀 Quick Start

### 1. Compile
```bash
cd TetrisConsole
g++ -std=c++11 -o tetris *.cpp
```

### 2. Run
```bash
./tetris
```

### 3. Play
```
A/D  - Move left/right
X    - Drop faster
Q    - Quit
```

## ✨ Features
- ✅ 7 Tetris pieces: I, O, T, S, Z, J, L
- ✅ Automatic gravity (500ms per frame)
- ✅ Collision detection & line clearing
- ✅ Cross-platform support (Windows/macOS/Linux)
- ✅ OOP architecture (4 independent classes)
- ✅ Non-blocking keyboard input

## 📁 Project Structure
```
TetrisConsole/
├── main.cpp              - Entry point (5 lines)
├── Block.h/cpp           - Tetris piece class
├── Board.h/cpp           - Game grid management
├── Game.h/cpp            - Game loop controller
├── Platform.h/cpp        - Cross-platform abstraction
├── README.md             - This file
├── DOCUMENTATION.md      - Full documentation
└── tetris                - Compiled executable
```

## 🏗️ Architecture Overview

```
Game (Main Controller)
├─ Board (20x15 grid)
│  ├─ init()           - Initialize board
│  ├─ draw()           - Render to terminal
│  ├─ canMove()        - Collision detection
│  ├─ placeBlock()     - Write block to board
│  ├─ removeBlock()    - Erase block from board
│  └─ removeLine()     - Clear filled lines
│
├─ Block (Tetris Piece)
│  ├─ 7 piece types (I, O, T, S, Z, J, L)
│  ├─ moveX/moveY      - Position updates
│  └─ getCell()        - Get block cell content
│
└─ Platform (OS-specific I/O)
   ├─ Input class      - Non-blocking keyboard
   └─ Console class    - Screen management
```

## 📊 Statistics
| Metric | Value |
|--------|-------|
| **Total Lines** | 502 |
| **Classes** | 4 |
| **Methods** | 30+ |
| **Supported OS** | 3 (Win/Mac/Linux) |
| **C++ Standard** | C++11 |

## 🖥️ System Requirements
- **Compiler**: GCC 4.7+, Clang 3.3+, or MSVC 2012+
- **Terminal**: 80x24 minimum
- **OS**: Windows, macOS, or Linux

## 📖 Documentation
- **[DOCUMENTATION.md](DOCUMENTATION.md)** - Complete project documentation
  - Detailed class explanations
  - Game loop walkthrough
  - Troubleshooting guide
  - Future improvements

## 🔄 Game Loop (Every 500ms)
1. Remove old block position
2. Process keyboard input (a/d/x/q)
3. Apply gravity (fall 1 row)
4. Check for line completion & clear
5. Render board to terminal
6. Sleep 500ms

## 🚀 Future Enhancements
- [ ] Block rotation
- [ ] Score system & high score
- [ ] Difficulty levels
- [ ] Ghost block preview
- [ ] Sound effects
- [ ] Next piece display

## 📝 Version History
- **v2.0** (Current) - OOP refactored with cross-platform support
- **v1.0** - Original procedural implementation

## 🐛 Common Issues & Solutions

### Terminal corrupted after exiting
**Solution**: Rerun the game (it auto-restores) or type `reset`

### Can't see blocks moving
**Possible causes**:
- Terminal too small (needs 80x24)
- Check if game is running with `./tetris`

### Compilation error
**Ensure**:
- C++11 compiler: `g++ -std=c++11`
- All files in same directory
- No modification to source files

---

**Author**: Oanh Pham  
**Last Updated**: April 2026  
**License**: Educational use
