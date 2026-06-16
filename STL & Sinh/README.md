## STL C++

**STL** (Standard Template Library) là một thư viện chuẩn trong C++, cung cấp những cấu trúc dữ liệu, thuật toán, bộ lặp để giúp lập trình viên code nhanh và hiệu quả hơn

Khác với các dạng bài toán **Sinh**, **Quay lui**, **Tìm kiếm**, ... không thật sự có bài toán nào gọi là STL C++ cả. Thay vào đó, **STL được sử dụng làm công cụ** để giải các dạng toán trên.

**Tài liệu tham khảo**:

- [Vector - Blog ProPTIT](https://blog.proptit.com/posts/vector-cong-cu-quan-ly-mang-manh-me-trong-c-2328)
- [Set - Blog ProPTIT](https://blog.proptit.com/posts/set-trong-c-6157)
- [Map - Blog ProPTIT](https://blog.proptit.com/posts/gioi-thieu-map-trong-c-2029)
- Internet

**Một số điều cần biết khi sử dụng**

Các CTDL trong STL rất tiện lợi, nhưng cần chú ý một số điều sau để sử dụng hiệu quả và tránh sai vặt.

- Vector có cơ chế tự động cấp phát lại bộ nhớ khi thêm quá nhiều phần tử. Quá trình cấp phát này có độ phức tạp là O(n). Tức là cấp phát lại cho n phần tử thì sẽ tốn đúng n bước.
  - Khi làm việc với vector, nếu có thể thì hãy luôn khai báo sẵn một số lượng phần tử nhất định `vector<int> a(1005)`.
  - Hoặc đơn giản là `a.reserve(1005)` để cấp phát sẵn phần tử.

- Hàm `.size()` dùng để đếm số lượng phần tử trong vector có **độ phức tạp O(n)** với n là số phần tử vector
  - Tuyệt đối tránh dùng vòng lặp như sau:

```cpp
for(int i = 0; i < v.size(); ++i)
     // code 

/*
Ta có n vòng lặp khác nhau.
Ở mỗi vòng lặp máy tính sẽ luôn kiểm tra `i < v.size()`.
Mỗi lần gọi `v.size()` mất n thao tác, n lần gọi sẽ mất n^2 thao tác.
Như vậy là ta đã có độ phức tạp cao ngay từ giai đoạn nhập xuất
*/
```

- Khi truyền vector vào một hàm, truyền với dạng `const vector<int>&` sẽ nhanh hơn. Dấu `&` sẽ truyền trực tiếp **địa chỉ** . Nếu chỉ truyền `vector<int>` không thì máy tính sẽ copy lần lượt từng phần tử của vector đó ra một vector tạm thời khác (**chậm**)
- Chung một công việc nhưng cái nhanh cái chậm:
  - O(n) `lower_bound(my_set.begin(), my_set.end(), val)`
  - O(logn) `my_set.lower_bound(val)`

## SINH

Một dạng bài tập thường gặp dưới dạng có những kết quả, **khả năng nào có thể được sinh ra** và **liệt kê ra**

Dạng bài này cần chú ý ba thứ:
- **Cấu hình đầu tiên** (để bắt đầu)
- **Cấu hình kết thúc** (để biết khi nào có thể dừng)
- **Cách để sinh ra cấu hình**

4 bài toán sinh cơ bản nhất cần phải biết là 
- **Sinh xâu nhị phân**
- **Sinh tổ hợp**
- **Sinh hoán vị**
- **Sinh phân hoạch**

Ở CodePTIT cũng có bài **Sinh mã Gray**. Để cẩn thận thì cũng nên học cái này.

**Bài xâu nhị phân** thì có thể sử dụng **sinh kế tiếp TRR1** hoặc **đệ quy**

**Bài tổ hợp và hoán vị** ngoài cách **sinh kế tiếp TRR1** ra thì mình sẽ chỉ cho mọi người mẹo khác ở buổi trao đổi.

**Sinh phân hoạch** thì không có (hoặc mình không biết) khung nào để áp dụng vào bài toán này. Đây là một thuật toán cần phải học, cần phải biết mới làm được chứ nghĩ thì lâu.

**Gray** sử dụng mẹo được học từ môn **Kỹ thuật số/Điện tử số**

## Code Template
- Mẫu code C++ có sẵn tất cả các thư viện, tối ưu nhập xuất I/O mà bạn nên áp dụng vào code của mình

