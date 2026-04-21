# 🎮 Game Tetris Console

Game Tetris (Xếp hình) cổ điển được lập trình bằng C++ với thiết kế hướng đối tượng (OOP) và hỗ trợ đa nền tảng (Windows, macOS, Linux).

## 🚀 Bắt đầu nhanh

### 1. Biên dịch (Compile)
```bash
cd TetrisConsole
g++ -std=c++11 -o tetris *.cpp
```

### 2. Chạy
```bash
./tetris
```

### 3. Chơi game
```
A/D  - Di chuyển trái/phải
X    - Rơi nhanh
Q    - Thoát
```

## ✨ Tính năng
- ✅ 7 loại khối Tetris: I, O, T, S, Z, J, L
- ✅ Gravity tự động (mỗi 500ms)
- ✅ Phát hiện va chạm & xóa dòng đầy
- ✅ Hỗ trợ đa nền tảng (Windows/macOS/Linux)
- ✅ Kiến trúc OOP (4 lớp độc lập)
- ✅ Xử lý input không chặn (non-blocking)

## 📁 Cấu trúc dự án
```
TetrisConsole/
├── main.cpp              - Điểm vào chương trình
├── Block.h/cpp           - Lớp Tetris piece
├── Board.h/cpp           - Lớp quản lý lưới game
├── Game.h/cpp            - Lớp điều phối game loop
├── Platform.h/cpp        - Lớp trừu tượng đa nền tảng
├── README.md             - File này
├── DOCUMENTATION.md      - Tài liệu chi tiết
└── tetris                - Tệp thực thi (executable)
```

## 🏗️ Tổng quan kiến trúc

```
Game (Bộ điều khiển chính)
├─ Board (lưới 20x15)
│  ├─ init()           - Khởi tạo board
│  ├─ draw()           - Vẽ lên terminal
│  ├─ canMove()        - Phát hiện va chạm
│  ├─ placeBlock()     - Ghi block lên board
│  ├─ removeBlock()    - Xóa block khỏi board
│  └─ removeLine()     - Xóa dòng đầy
│
├─ Block (Tetris Piece)
│  ├─ 7 loại khối (I, O, T, S, Z, J, L)
│  ├─ moveX/moveY      - Cập nhật vị trí
│  └─ getCell()        - Lấy nội dung ô
│
└─ Platform (I/O tuỳ thuộc OS)
   ├─ Lớp Input        - Bàn phím không chặn
   └─ Lớp Console      - Quản lý màn hình
```

## 📊 Thống kê
| Chỉ số | Giá trị |
|--------|--------|
| **Tổng dòng code** | 502 |
| **Lớp (Classes)** | 4 |
| **Hàm (Methods)** | 30+ |
| **Hỗ trợ OS** | 3 (Win/Mac/Linux) |
| **Chuẩn C++** | C++11 |

## 🖥️ Yêu cầu hệ thống
- **Compiler**: GCC 4.7+, Clang 3.3+, hoặc MSVC 2012+
- **Terminal**: Tối thiểu 80x24
- **OS**: Windows, macOS, hoặc Linux

## 📖 Tài liệu
- **[DOCUMENTATION.md](DOCUMENTATION.md)** - Tài liệu hoàn chỉnh
  - Giải thích chi tiết các lớp
  - Walkthrough game loop
  - Hướng dẫn xử sự cố
  - Các cải tiến trong tương lai

## 🔄 Vòng lặp game (mỗi 500ms)
1. Xóa vị trí block cũ
2. Xử lý input từ bàn phím (a/d/x/q)
3. Áp dụng gravity (khối rơi 1 ô)
4. Kiểm tra xóa dòng đầy
5. Vẽ board lên terminal
6. Đợi 500ms

## 🚀 Tính năng sắp thêm
- [ ] Xoay khối (Rotation)
- [ ] Hệ thống điểm & điểm cao nhất
- [ ] Các cấp độ khó khác nhau
- [ ] Xem trước khối tiếp theo (Ghost block)
- [ ] Hiệu ứng âm thanh
- [ ] Hiển thị khối sắp tới

## 📝 Lịch sử phiên bản
- **v2.0** (Hiện tại) - Refactor OOP với hỗ trợ đa nền tảng
- **v1.0** - Triển khai procedural ban đầu

## 🐛 Các vấn đề thường gặp & Giải pháp

### Terminal bị lỗi sau khi thoát game
**Giải pháp**: Chạy lại game (tự động khôi phục) hoặc gõ `reset`

### Không thấy khối di chuyển
**Nguyên nhân có thể**:
- Terminal quá nhỏ (cần 80x24)
- Kiểm tra game đã chạy: `./tetris`

### Lỗi biên dịch
**Đảm bảo**:
- Dùng C++11: `g++ -std=c++11`
- Tất cả file ở cùng thư mục
- Không sửa đổi tệp nguồn

---

**Tác giả**: 25730131, 25730120, 25730138, 25730108, 25730141 
**Cập nhật lần cuối**: Tháng 4 năm 2026  
**Giấy phép**: Sử dụng cho mục đích học tập
