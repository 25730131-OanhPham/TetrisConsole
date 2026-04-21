# 🎮 TETRIS CONSOLE GAME - DOCUMENTATION

## 📋 Mục lục
1. [Tổng quan dự án](#tổng-quan-dự-án)
2. [Tính năng](#tính-năng)
3. [Yêu cầu hệ thống](#yêu-cầu-hệ-thống)
4. [Cài đặt & Chạy](#cài-đặt--chạy)
5. [Hướng dẫn sử dụng](#hướng-dẫn-sử-dụng)
6. [Kiến trúc dự án](#kiến-trúc-dự-án)
7. [Chi tiết các lớp](#chi-tiết-các-lớp)
8. [Game Loop chi tiết](#game-loop-chi-tiết)
9. [Hướng phát triển](#hướng-phát-triển)
10. [Các vấn đề & Giải pháp](#các-vấn-đề--giải-pháp)
11. [Thống kê dự án](#thống-kê-dự-án)
12. [Tài liệu tham khảo](#tài-liệu-tham-khảo)
13. [Tác giả](#tác-giả)
14. [Hỗ trợ & Feedback](#hỗ-trợ--feedback)
---

## 1. Tổng quan dự án

**Tên**: Tetris Console Game  
**Ngôn ngữ**: C++ (C++11)  
**Loại**: Game console 2D  
**Mô tả**: 
- Triển khai game Tetris cổ điển trên console
- Refactor từ code procedural sang Object-Oriented Programming (OOP)
- Hỗ trợ đa nền tảng (Windows, macOS, Linux)

### Lịch sử phát triển
```
v1.0 (Original)  → Procedural code (130 lines, global variables)
v2.0 (Refactor)  → OOP architecture (502 lines, 4 classes, cross-platform)
```

---

## 2. Tính năng

### Tính năng chính
- ✅ **7 loại khối Tetris**: I, O, T, S, Z, J, L
- ✅ **Gravity**: Khối rơi tự động (500ms/frame)
- ✅ **Collision Detection**: Phát hiện va chạm tường & block
- ✅ **Line Clearing**: Xóa dòng đầy, dồn dòng trên xuống
- ✅ **Điều khiển**: a/d (trái/phải), x (rơi nhanh), q (thoát)

### Tính năng kỹ thuật
- ✅ **OOP Architecture**: 4 lớp độc lập (Block, Board, Game, Platform)
- ✅ **Cross-platform**: Windows, macOS, Linux
- ✅ **Non-blocking Input**: Đọc input ngay mà không cần Enter
- ✅ **Clean Code**: Tách biệt trách nhiệm, dễ mở rộng

---

## 3. Yêu cầu hệ thống

### Yêu cầu tối thiểu
- **C++ Compiler**: GCC 4.7+ hoặc clang 3.3+
- **Tiêu chuẩn**: C++11 trở lên
- **Terminal**: 80x24 (80 cột x 24 hàng)

### Hỗ trợ OS
| OS | Hỗ trợ | Ghi chú |
|---|--------|--------|
| Windows | ✅ | Dùng `conio.h` |
| macOS | ✅ | Dùng `termios.h` + ANSI codes |
| Linux | ✅ | Dùng `termios.h` + ANSI codes |

---

## 4. Cài đặt & Chạy

### 1. Clone dự án
```bash
cd /path/to/project
cd TetrisConsole
```

### 2. Compile
```bash
# Dùng GCC
g++ -std=c++11 -o tetris *.cpp

# Hoặc dùng Clang
clang++ -std=c++11 -o tetris *.cpp

# Hoặc dùng Make (nếu có Makefile)
make
```

### 3. Chạy game
```bash
# Linux/macOS
./tetris

# Windows (MinGW)
tetris.exe
```

### 4. Cleanup
```bash
# Xóa executable
rm tetris

# Xóa tất cả object files
make clean
```

---

## 5. Hướng dẫn sử dụng

### Điều khiển
| Phím | Chức năng |
|------|----------|
| **A** | Di chuyển khối sang trái |
| **D** | Di chuyển khối sang phải |
| **X** | Rơi nhanh (1 ô xuống) |
| **Q** | Thoát game |

### Gameplay
1. **Khối rơi xuống**: Mỗi 500ms (điều chỉnh được)
2. **Xóa dòng**: Khi 1 dòng đầy (không có khoảng trống)
3. **Game Over**: Khi bấm Q

### Ví dụ chơi
```
Khởi động:
###############
#             #
#     I       #  ← Block mới
#     I       #
#     I       #
#     I       #
###############

Bấm D:
###############
#             #
#      I      #  ← Di chuyển sang phải
#      I      #
#      I      #
#      I      #
###############

Bấm X:
###############
#             #
#             #
#      I      #  ← Rơi nhanh 1 ô
#      I      #
#      I      #
#      I      #
###############
```

---

## 6. Kiến trúc dự án

### Cấu trúc File
```
TetrisConsole/
├── main.cpp           (5 dòng - Entry point)
├── Block.h/cpp        (80 dòng - Tetris piece)
├── Board.h/cpp        (90 dòng - Game grid)
├── Game.h/cpp         (100 dòng - Game controller)
├── Platform.h/cpp     (150 dòng - Cross-platform I/O)
├── tetris             (Executable)
└── README.md          (This file)
```

### Architecture Diagram
```
┌──────────────────────────────────────┐
│             main()                   │
│          (entry point)               │
└──────────────┬───────────────────────┘
               │
               ↓
        ┌──────────────┐
        │   Game       │ ← Main controller
        │              │
        ├──────────────┤
        │ - board      │ (Board instance)
        │ - currentBlock│ (Block instance)
        │ - isRunning  │ (bool)
        └──────┬───┬──┘
               │   │
         ┌─────┘   └─────┐
         ↓                ↓
    ┌────────┐        ┌────────┐
    │ Board  │        │ Block  │
    │        │        │        │
    ├────────┤        ├────────┤
    │- board │        │- blocks│
    │[20×15] │        │ (7)    │
    └────┬───┘        └────┬───┘
         │                 │
         └────────┬────────┘
                  ↓
          ┌───────────────┐
          │  Platform     │ ← Cross-platform
          │               │
          ├───────────────┤
          │ - Input class │ (OS-specific)
          │ - Console class│ (OS-specific)
          └───────────────┘
```

### Class Relationships
```
Game (Aggregation)
├─ has-a Board
│  └─ contains board[20×15]
│  └─ methods: init(), draw(), canMove(), placeBlock(), removeBlock()
│
├─ has-a Block
│  └─ contains blocks[16×4×4]
│  └─ methods: getCell(), moveX(), moveY(), rotate()
│
└─ uses Platform
   └─ Input (static methods)
   └─ Console (static methods)
```

---

## 7. Chi tiết các lớp

### 1. Block Class
**File**: `Block.h`, `Block.cpp`
**Mục đích**: Quản lý một khối Tetris

**Public Methods**:
```cpp
Block(int type, int startX, int startY);  // Constructor
int getX() const;                         // Lấy vị trí X
int getY() const;                         // Lấy vị trí Y
int getType() const;                      // Lấy loại block
char getCell(int row, int col) const;     // Lấy ký tự tại (row, col)
void setPosition(int x, int y);           // Đặt vị trí
void moveX(int dx);                       // Di chuyển X
void moveY(int dy);                       // Di chuyển Y
void rotate();                            // Xoay (TODO)
```

**Member Variables**:
```cpp
static const char blocks[16][4][4];  // 16 shapes, mỗi 4×4
int blockType;                       // Type 0-15
int x, y;                           // Position on board
```

### 2. Board Class
**File**: `Board.h`, `Board.cpp`

**Mục đích**: Quản lý lưới game 20×15

**Public Methods**:
```cpp
void init();                                    // Khởi tạo board
void draw() const;                              // Vẽ board
bool canMove(const Block& block, int dx, int dy) const;  // Kiểm tra va chạm
void placeBlock(const Block& block);            // Ghi block lên board
void removeBlock(const Block& block);           // Xóa block khỏi board
void removeLine();                              // Xóa dòng đầy
char getCell(int row, int col) const;           // Lấy ô
bool isLineFull(int row) const;                 // Kiểm tra dòng đầy
```

**Member Variables**:
```cpp
static const int HEIGHT = 20;   // Chiều cao
static const int WIDTH = 15;    // Chiều rộng
char board[20][15];             // Lưới chính
```

### 3. Game Class
**File**: `Game.h`, `Game.cpp`

**Mục đích**: Điều phối logic game chính

**Public Methods**:
```cpp
Game();                    // Constructor (setup console, init board)
~Game();                   // Destructor (restore console)
void start();              // Vòng lặp chính
void update();             // Cập nhật 1 frame
void handleInput();        // Xử lý phím người chơi
void spawnNewBlock();      // Tạo block mới
bool isGameOver() const;   // Kiểm tra game kết thúc
```

**Member Variables**:
```cpp
Board board;          // Lưới game
Block currentBlock;   // Block hiện tại
bool isRunning;       // Cờ vòng lặp
```

### 4. Platform Class
**File**: `Platform.h`, `Platform.cpp`
**Mục đích**: Tách biệt OS-specific code (Windows vs Unix)

**Input Class** (Static methods):
```cpp
static bool isKeyPressed();    // Kiểm tra có phím bấm
static char getChar();         // Lấy ký tự
static void setupConsole();    // Setup raw input mode
static void restoreConsole();  // Restore console
```

**Console Class** (Static methods):
```cpp
static void clear();           // Clear screen
static void setCursorHome();   // Cursor về đầu
```

**Triển khai**:
- **Windows**: Dùng `conio.h` (`_kbhit()`, `_getch()`)
- **Unix/macOS/Linux**: Dùng `termios.h`, `select()`, ANSI codes

---

## 8. Game Loop (Vòng lặp chính)

### Flow của mỗi Frame (500ms)
```
Frame Start
    ↓
1. Remove block (xóa block cũ khỏi board)
    ↓
2. Handle Input (đọc phím a/d/x/q)
    ├─ a: moveX(-1)
    ├─ d: moveX(+1)
    ├─ x: moveY(+1)
    └─ q: isRunning = false
    ↓
3. Apply Gravity
    ├─ canMove(0, 1)? → moveY(+1) (rơi 1 ô)
    └─ No → placeBlock(), removeLine(), spawnNewBlock()
    ↓
4. Place block (ghi block hiện tại lên board)
    ↓
5. Draw (vẽ board ra terminal)
    ↓
6. Sleep (đợi 500ms)
    ↓
Frame End
```

### Pseudocode
```
while (isRunning) {
    // Remove old position
    board.removeBlock(currentBlock);
    
    // Get user input
    if (keyPressed) {
        char key = getKey();
        if (key == 'a' && canMove(-1, 0)) currentBlock.moveX(-1);
        if (key == 'd' && canMove(1, 0))  currentBlock.moveX(1);
        if (key == 'x' && canMove(0, 1)) currentBlock.moveY(1);
        if (key == 'q') isRunning = false;
    }
    
    // Apply gravity
    if (canMove(0, 1)) {
        currentBlock.moveY(1);  // Fall 1 row
    } else {
        // Block touched bottom
        board.placeBlock(currentBlock);
        board.removeLine();
        spawnNewBlock();
    }
    
    // Render
    board.placeBlock(currentBlock);
    board.draw();
    
    // Frame timing
    sleep(500ms);
}
```

---

## 9. Hướng phát triển

### Tính năng có thể thêm
- [ ] **Rotation**: Xoay khối (implement `Block::rotate()`)
- [ ] **Score System**: Đếm điểm khi xóa dòng
- [ ] **Levels**: Độ khó tăng dần (rơi nhanh hơn)
- [ ] **Ghost Block**: Hiển thị block shadow ở vị trí sẽ rơi
- [ ] **Hold Piece**: Giữ block hiện tại, swap sau
- [ ] **Next Piece**: Hiển thị block sắp tới
- [ ] **Sound**: Âm thanh khi xóa dòng, game over
- [ ] **High Score**: Lưu điểm cao nhất

### Cải tiến Code
- [ ] **Configuration**: Đặt tốc độ game, kích thước board
- [ ] **Unit Tests**: Test từng class riêng biệt
- [ ] **Makefile**: Tự động compile, clean, install
- [ ] **CMake**: Build system chuyên nghiệp
- [ ] **Documentation**: Add comments chi tiết hơn
- [ ] **Error Handling**: Better error messages

### Tối ưu hiệu năng
- [ ] **Double Buffering**: Tránh flicker khi vẽ
- [ ] **Frame Rate Control**: Điều chỉnh FPS
- [ ] **Input Queue**: Xử lý nhiều phím cùng lúc
- [ ] **Memory Optimization**: Reduce footprint

---

## 10. Các vấn đề & Giải pháp

### Vấn đề 1: Terminal bị lỗi sau khi thoát game
**Nguyên nhân**: `Input::restoreConsole()` không được gọi
**Giải pháp**: Destructor `~Game()` tự động restore console
```cpp
Game::~Game() {
    Input::restoreConsole();  // Restore terminal settings
}
```

---

### Vấn đề 2: Khối chỉ hiển thị I và O
**Nguyên nhân**: `getRandomBlockType()` trả về `rand() % 7` nhưng Block.cpp có 7 loại
**Giải pháp**: Tổ chức Block.cpp chỉ có 7 shape cơ bản
```cpp
// Type 0: I-Block
// Type 1: O-Block
// Type 2: T-Block
// Type 3: S-Block
// Type 4: Z-Block
// Type 5: J-Block
// Type 6: L-Block
```

---

### Vấn đề 3: Input không hoạt động trên macOS/Linux
**Nguyên nhân**: Dùng `conio.h` (chỉ có trên Windows)
**Giải pháp**: Platform abstraction layer
```cpp
#ifdef _WIN32
    // Windows: use conio.h
#else
    // Unix: use termios.h + select()
#endif
```

---

## 11. Thống kê dự án

| Metric | Giá trị |
|--------|--------|
| **Tổng dòng code** | 502 |
| **Files** | 9 (8 source + 1 exec) |
| **Classes** | 4 |
| **Methods** | 30+ |
| **Hỗ trợ OS** | 3 (Windows, macOS, Linux) |
| **C++ Standard** | C++11 |
| **Compile Time** | < 1 giây |
| **Binary Size** | ~100 KB |

---

## 12. Tài liệu tham khảo

### C++ References
- [cppreference.com](https://en.cppreference.com/) - C++ Standard Library
- [cplusplus.com](http://www.cplusplus.com/) - C++ tutorials

### Game Development
- [Tetris Guidelines](https://tetris.fandom.com/wiki/Tetris_Guideline) - Official Tetris specs
- [Game Loop Architecture](https://gameprogrammingpatterns.com/game-loop.html) - Design patterns

### Platform-specific
- [POSIX termios](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/termios.h.html)
- [Windows conio.h](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/conio-functions)

---

## 13. Tác giả
Tác giả: 25730131, 25730120, 25730138, 25730108, 25730141 
Dự án: Tetris Console Game
Ngày hoàn thành: April 2026

---

## 14. Hỗ trợ & Feedback

Nếu có vấn đề:
1. Kiểm tra **Các vấn đề & Giải pháp** phía trên
2. Đảm bảo compiler hỗ trợ C++11 trở lên
3. Kiểm tra terminal có đủ 80x24 ô không

---

**Last Updated**: April 21, 2026  
**Version**: 2.0 (OOP Refactored)
