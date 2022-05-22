# Dự án cuối kì lớp học phần INT2215 1 - Lập trình nâng cao
## Trần Mạnh Dũng - 21020119

### 1. Hướng dẫn cài đặt
  * Lưu ý: Sử dụng file project của Visual Studio Community 2019
  * Tải project [ tại đây ](https://drive.google.com/file/d/1LxT5TKlbBu4blCyQavVRdrDbN4gQnpua/view?usp=sharing)
  * Giải nén file vừa tải
  * Chạy chương trình:
    + Mở file 2 Cars.sln bằng Visual Studio 2019
    + Cài Solution Platforms x64
    + Cài Solution Configurations Release
    + Nhấn F5 hoặc click vào Local Windows Debugger để chạy

### 2. Mô tả chung về trò chơi, các ý tưởng chính
#### a) Mô tả chung về trò chơi
  * Tên trò chơi: 2 Cars
  * Ảnh Demo:
![demo](https://user-images.githubusercontent.com/100196588/169719921-6d7ef496-67ba-41f6-84d2-2eb1c76f41e4.png)
  * Cách chơi:
    + Sử dụng các phím A - D để điều khiển xe bên trái sang trái - phải, các phím J - L để điều khiển xe bên phải sang trái - phải
    + Ăn các vật thể hình tròn để ghi điểm và tránh các vật thể hình vuông trên đường đi
    + Mỗi hình tròn ăn được sẽ tương ứng với 1 điểm. Số điểm càng cao, tốc độ càng nhanh
#### b) Các ý tưởng chính:
  * Hệ thống các đối tượng: Xe, các vật thể(hình vuông, hình tròn)
  * Đồ họa đơn giản, dễ hiểu, dễ chơi
### 3. Các chức năng được cài đặt trong trò chơi
  * Các chức năng chơi, tương tác với phím
  * Hiển thị điểm số ở góc trên bên trái màn hình
  * Video demo [ tại đây ]()
### 4. Các kỹ thuật lập trình được sử dụng trong chương trình
  * Kỹ thuật lập trình đồ họa bằng SFML
  * Con trỏ, mảng, sinh số ngẫu nhiên
  * Xử lí va chạm
### 5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình
#### a) Điều tâm đắc:
  * Học được các kiến thức về đồ họa, SFML. Biết và hiểu cơ bản cách tạo ra 1 game 2D
  * Củng cố, nâng cao kiến thức về C++
#### b) Hướng phát triển:
  * Thêm âm thanh
  * Thêm menu(bảng xếp hạng, cài đặt các thông số game...)
  * Thêm các vật thể là phần quà đặc biệt
### 6. Các nguồn tài liệu tham khảo
  * Các câu lệnh trong SFML:
    + https://www.sfml-dev.org/tutorials/2.5/
    + https://www.youtube.com/c/SonarSystemsCoUk
