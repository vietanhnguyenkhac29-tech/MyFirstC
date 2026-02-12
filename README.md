# 🚀 MyFirstC-AllInOne

**MyFirstC-AllInOne** là dự án tổng hợp đầu tay của mình trên hành trình chinh phục ngôn ngữ lập trình C. Thay vì các bài tập rời rạc, dự án này kết hợp nhiều công cụ thực tiễn vào một hệ thống quản lý tập trung thông qua giao diện dòng lệnh (Console Interface).

---

## 📋 Giới thiệu dự án
Dự án được xây dựng từ việc tích hợp 3 công cụ độc lập: Máy tính cơ bản, Chuyển đổi ngoại tệ và Quản lý hồ sơ. Toàn bộ hệ thống được bảo vệ bởi một lớp đăng nhập để đảm bảo tính riêng tư.

### 🔑 Tài khoản đăng nhập mặc định:
- **Username:** `vanakao`
- **Password:** `9987`

---

## ✨ Các tính năng chính
Hệ thống sử dụng Menu điều hướng thông minh để người dùng dễ dàng chuyển đổi giữa các chức năng:

1. **Máy tính bỏ túi (Calculator):**
   - Hỗ trợ các phép tính: Cộng (+), Trừ (-), Nhân (*), Chia (/).
   - Có logic kiểm tra và ngăn chặn lỗi chia cho 0.
2. **Chuyển đổi tiền tệ (Currency Converter):**
   - Chuyển đổi từ VND sang 6 loại ngoại tệ phổ biến: USD, EUR, JPY, GBP, AUD, CAD.
   - Tỉ giá được cập nhật theo các hằng số thực tế trong code.
3. **Quản lý hồ sơ (Profile Manager):**
   - Nhập thông tin cá nhân: Tên, Tuổi, Địa chỉ, Ngân hàng, Số dư...
   - Hiển thị bảng tổng kết hồ sơ chuyên nghiệp sau khi nhập.

---

## 🛠 Kỹ thuật lập trình đã áp dụng
Để hoàn thành dự án này, mình đã học và áp dụng các kiến thức quan trọng trong lập trình C:
* **Modular Programming:** Tách biệt các chức năng thành các hàm (`void functions`) giúp code sạch sẽ và dễ bảo trì.
* **Input Buffer Handling:** Xử lý triệt để lỗi "trôi lệnh" khi nhập chuỗi sau khi nhập số bằng cách sử dụng hàm tự định nghĩa `clearInputBuffer()`.
* **Flow Control:** Sử dụng vòng lặp `while` và cấu trúc rẽ nhánh `switch-case` để tạo luồng người dùng không bị ngắt quãng.
* **String Processing:** Sử dụng thư viện `<string.h>` và hàm `strcmp` để xác thực thông tin đăng nhập.

---

## 📖 Hướng dẫn cài đặt và sử dụng
1. **Yêu cầu:** Máy tính đã cài đặt trình biên dịch C (như GCC).
2. **Biên dịch:**
   ```bash
   gcc compelte.c -o MyFirstC
3.**Chạy ứng dụng**
Bash
./MyFirstC

💭 Lời kết
Đây là sản phẩm đánh dấu bước khởi đầu của mình với tư cách là một lập trình viên. Dự án tuy nhỏ nhưng giúp mình hiểu sâu về logic điều khiển và cách tổ chức một chương trình có cấu trúc. Rất mong nhận được sự góp ý từ mọi người!

Ghi chú: Dự án được phát triển bởi vanakao.
