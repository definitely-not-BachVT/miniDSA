**Record:** https://youtu.be/enzX2NDdt1M

# TOÁN CƠ BẢN

## Kiểm tra số nguyên tố

**Định nghĩa:** Số nguyên tố là số chỉ có hai ước là 1 và chính nó. Lưu ý số 1 không phải là số nguyên tố.

**Ví dụ:** 
- 2, 3, 5 là số nguyên tố.
- 6 không phải là số nguyên tố vì nó có 4 ước là {1, 2, 3, 6}.

**Code O($n$):** 

Ý tưởng là kiểm tra từng số từ một tới $n$ để đếm số ước. Không nên dùng loại này

**Code $O(\sqrt{n})$**

Một số $n$ có thể được phân tích dưới dạng $n$ = $a$ * $b$.

Nếu tìm được $a$ thì ta sẽ tìm được $b$ tương ứng, nên ta chỉ cần duyệt $a$ trong khoảng từ 1 tới $\sqrt{n}$ để kiểm tra xem $n$ chia hết cho bao nhiêu $a$

**Dưới đây là hai code kiểm tra thực hiện tư tưởng trên**

```cpp
// Kiểm tra với bước nhảy 1. Nếu muốn bước nhảy là 2, bắt đầu kiểm tra từ số 3 ở vòng trong vòng lặp nhé.
bool snt(int n)
{
     for(int i = 2; i * i <= n; ++i)
          if(n % i == 0)
               return false;
     return true;
}
```

```cpp
// Kiểm tra với bước nhảy là 6
bool snt(long long n)
{
     if(n == 2 || n == 3)
          return true;
     if(n < 2 || n % 2 == 0 || n % 3 == 0)
          return false;

     for(long long i = 5; i * i <= n; i += 6)
          if(n % i == 0 || n % (i + 2) == 0)
               return false;
     return true;
}
```

## Sàng số nguyên tố

Cơ bản nhất chúng ta sẽ sàng số nguyên tố với **Sàng Eratosthenes**.

**Sàng Eratosthenes** giả định tất cả **các số ban đầu đều là số nguyên tố (trừ 0 và 1)**. Sau đó ta duyệt từ 2 (a.k.a số nguyên tố đầu tiên) đến $\sqrt{n}$. Nếu số đang xét là số nguyên tố, ta sẽ loại bỏ tất cả các bội của số đó ra khỏi tập hợp.

**Ví dụ:** 

- Chúng ta biết 2 là một số nguyên tố. Vì vậy tất cả các số là bội của 2 như 4, 6, 8, .. đều không phải là số nguyên tố.

- Trong khi đó 3 - một số nguyên tố khác, không phải là bội của 2. Chúng ta sẽ tiếp tục loại các bội của 3 đi để làm điều này.

**Tối ưu**
- Bằng việc quan sát, ta nhận thấy không nhất thiết phải loại tất cả các bội của $x$ kể từ $2*x$ trở đi. Ta sẽ loại từ $x*x$.

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
bool isPrime[MAXN + 5];

vector<int> snt; // sẽ được dùng cho các phân tích thành các thừa số nguyên tố

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
        if (isPrime[i]) 
            for (int j = i * i; j <= MAXN; j += i) 
                isPrime[j] = false;

     for(int i = 2; i < MAXN; ++i)
          if(isPrime[i])
               snt.push_back(i);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    sieve();
}
```

**Minh họa**

Dưới đây là minh họa chạy tay cho sàng số nguyên tố này.

[Visualizer](https://www.learnmathclass.com/arithmetic/visual-tools/eratosthenes-sieve)

## GCD & LCM

**Ước chung lớn nhất (Manual)**

**Thuật toán Euclid** dựa trên một định lý toán học cơ bản:
- Ước chung lớn nhất của hai số $a$ và $b$ (với $a > b$) cũng chính là ước chung lớn nhất của $b$ và phần dư của $a$ chia cho $b$

- $\text{GCD}(a, b) = \text{GCD}(b, r)$

```cpp
int gcd(int a, int b)
{
     int temp;
     while(a != 0)
     {
          temp = a;
          a = b % a;
          b = temp;
     }
     return b;
}
```

**Ước chung lớn nhất (built-in)**

Sử dụng hàm có sẵn **trong C++ 17** (nếu dùng được)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int x, y; cin >> x >> y;
     cout << gcd(x, y) << "\n";
}

```

**Bội chung nhỏ nhất**

Sử dụng công thức hoặc hàm có sẵn **trong C++ 17**

```cpp
lcm(a, b) = a * b / gcd(a, b);
// hoặc viết như sau để chống tràn số
lcm(a, b) = a / gcd(a, b) * b;
```

```cpp
// Có sẵn ở C++ 17 trở lên. Check compiler trước khi nộp nhé
cout << lcm(a, b);
```

## Đồng dư thức

Thường các bài có kết quả lớn sẽ được đem chia dư cho một số gì đó, thường là MOD = 1e9 + 7;

Số này là một số vừa đẹp vì: Nó gần với giới hạn của kiểu `int`, và nó là một số nguyên tố. Trong đồng dư thức, để tính được $1/a$ % MOD ta cần dùng nghịch đảo modulo. Để dùng nghịch đảo Modulo ta cần biết nghịch đảo Euler. Nghịch đảo Euler cho một số nguyên tố rất đẹp, và cũng là lí do khiến 1e9 + 7 (một số nguyên tố) được sử dụng nhiều.

**Mở rộng**
- **Phi hàm Euler:**  số lượng các số nguyên dương từ $1$ đến $n$ mà nguyên tố cùng nhau với $n$ (nghĩa là có Ước chung lớn nhất với $n$ bằng 1). 
  - **Phi hàm Euler của số nguyên tố p là p - 1**
- **Nghịch đảo Modulo:** Áp dụng vào các bài toán như đã giới thiệu ở trên

Code Euler:
```cpp
long long phi(long long n)
{
     long long result = n;

     for (long long i = 2; i * i <= n; i++)
     {

          if (n % i == 0)
          {

               while (n % i == 0)
                    n /= i;

               result -= result / i;
          }
     }

     if (n > 1)
          result -= result / n;

     return result;
}
```

# Quay lui - Nhánh cận

**Khái niệm**

- **Quay lui (Backtracking)** là một chiến lược thử có tổ chức dựa trên đệ quy. Ý tưởng của quay lui là tìm lời giải từng bước, mỗi bước chọn một trong số các lựa chọn khả dĩ và đệ quy.

- Ngay khi phát hiện ra một hướng đi không thể dẫn đến một giải pháp hợp lệ, thuật toán sẽ "quay lui" (hủy bỏ bước vừa thực hiện) để quay lại ngã rẽ trước đó và thử một lựa chọn khác.
  
- **Nhánh cận** là xem xét xem cấu hình/lựa chọn hiện tại liệu có thể đi tới kết quả tốt hơn kết quả từng được ghi nhận hay không. Nếu có thể, đi tiếp. Nếu không thì dừng lại và thử nhánh khác.

- **Nhánh cận** là kỹ thuật dùng để tối ưu thời gian thuật toán quay lui.
- Người ta thường quan sát bằng nhiều cách, một số cách hay gặp như:
  - Liệu đi cách này có trực tiếp dẫn tới kết quả sai không
  - Biết trước min/max của mảng và biết khoảng cách từ cấu hình hiện tại tới cuối con đường để chuẩn đoán xem liệu con đường này có còn ổn không
  - Vượt qua một giới hạn nào đó
  - ....

Khi code một hàm để quay lui, cần chú ý những điều sau:
- Trạng thái bắt đầu của hàm
- Điều kiện kết thúc của hàm
- Đối với phần code thực hiện thử từng khả năng có thể (Format)
  -  Thao tác chọn khả năng đó (nếu thỏa mãn điều kiện)
  -  Gọi đệ quy đến hàm của bước tiếp theo
  -  Thao tác bỏ chọn khả năng đó
- Điều kiện kiểm tra rẽ nhanh (nếu có)

Format code trên thường được mình sử dụng. Có thể một số bài toán sẽ có sự tùy chỉnh cho hợp lý, nên bạn chỉ nên coi Format trên là tham khảo thôi nhé.
  
**Điển hình:**
- Bài toán n-queen
- Rút tiền ở cây ATM
- Tập con có tổng bằng K

**[Bài tập mẫu 1](https://code.ptit.edu.vn/student/question/DSA02024) và [lời giải của nó](https://onecompiler.com/cpp#draft-sy9x)**

**[Bài tập mẫu 2](https://code.ptit.edu.vn/student/question/DSA05009) và [lời giải (chưa tối ưu nhất)](https://onecompiler.com/cpp#draft-8aqy)**

## Tìm kiếm nhị phân

**Khái niệm**

 **Tìm kiếm nhị phân** (aka BS) là thuật toán thực hiện tìm kiếm trên một mảng đã sắp xếp (tăng hoặc giảm dần) bằng cách liên tục chia khoảng tìm kiếm thành một nửa cho tới khi tìm được kết quả.

Từ mẫu tìm kiếm nhị phân có sẵn, bạn có thể **tùy chỉnh một số chỗ** như (left < right) thành <=, từ cập nhật mid = left + 1 hay mid = left, .... để tạo ra nhiều loại tìm kiếm nhị phân khác nhau, giải quyết các bài toán cụ thể như
  - Số đầu tiên lớn hơn x
  - Sô đầu tiên lớn hơn hoặc bằng x
  - Số đầu tiên nhỏ hơn x
  - ....
  
**Ứng dụng**
- Tìm kiếm/Kiểm tra sự tồn tại
- Các bài toán mà sự phụ thuộc của kết quả với đầu vào có tính đơn điệu

**C++ 17 Built-in**
- `lower_bound()`
- `upper_bound()`
- `binary_search()`

## Meet in the Middle

**Khái niệm**

- MITM là một kỹ thuật giải bài được sử dụng khi đầu vào nhỏ nhưng không đủ nhỏ để có thể thực hiện một bài toán.

**Ví dụ:**
- Trong bài toán sinh xâu nhị phân đối xứng có độ dài $n$ $(n <= 40)$, thay vì trực tiếp sinh ra các xâu có 40bit (rất rất lâu) thì chúng ta chỉ xây dựng một nửa xâu thôi rồi lật ngược nó lại để ghép thành xâu có đủ độ dài.
- Quán nét nằm ở giữa quãng đường từ nhà bạn tới cốt của bạn. Để gặp nhau thay vì bạn phải đi tới nhà cốt, hai người có thể cùng đi tới quán điện tử.

Khi cố gắng giải bài toán từ hai đầu, hoặc giải các bài toán được chia nhỏ ra rồi kết hợp lại, chúng ta sẽ giải được bài toán với độ phức tạp đủ nhỏ.

**Thường gặp**
- Bài toán kiểm tra tập con có tổng bằng K
- Bài toán chia đều sao cho chênh lệch nhỏ nhất
- Các bài toán sinh nhiều cấu hình, trong đó khi số bước từ cấu hình xuất phát tới cấu hình hiện tại càng tăng thì độ phức tạp càng tăng cao. (CodePTIT - HEXGAME)

