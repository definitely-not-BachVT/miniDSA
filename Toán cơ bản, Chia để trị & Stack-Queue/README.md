Record: https://youtu.be/lGrc1g7sh9o

## Lũy thừa nhanh

**Cơ sở**

Phương pháp thực hiện phép tính lũy thừa nhanh bằng cách thay cho nhân trực tiếp số $a$ đủ $n$ lần (như hàm `pow()` thường làm)

Ý tưởng của thuật toán dựa trên cở sở sau:
  - Nếu $n$ chẵn: $a^n = (a^{\frac{n}{2}})^2$
  - Nếu $n$ lẻ: $a^n = a \cdot a^{n-1} = a \cdot (a^{\frac{n-1}{2}})^2$  

Bằng cách liên tục chia đôi số mũ $n$, số phép nhân cần thiết sẽ giảm xuống bằng với số bit của $n$ (khoảng $\log_2 n$ phép tính).

**Triển khai**

Trong C++, thường có hai cách để triển khai thuật toán này là **đệ quy** hoặc **vòng lặp**

Thường thì lũy thừa nhanh sẽ được triển khai cùng một số để chia lấy phần dư (mod, thường là 1e9 + 7). Nếu không có thì chúng ta đơn giản là bỏ m đi thôi

```cpp
long long binpow(long long a, long long n, long long m)
{
     if (n == 0)
          return 1;

     long long res = binpow(a, n / 2, m);
     
     res = (res * res) % m;
     if (n % 2 != 0)
          return (res * (a % m)) % m;

     return res;
}
```

```cpp
long long binpow(long long a, long long b, long long m)
{
     long long ans = 1;
     while(b)
     {
          if(b % 2)
               ans = ans * a % m;
          a = a * a % m;

          b /= 2;
     }
     return ans;
}
```

## Cộng nhị phân

- Ý tưởng tương tự lũy thừa nhanh, nhưng đổi phép nhân thành phép cộng.
- Không sử dụng nhiều, nhưng nên biết để thực hiện các phép toán cẩn thận khi các số gần giới hạn tràn.

## Tổ hợp, chỉnh hợp

Có thể tiếp cận bằng chính công thức tính Ckn và Akn.
-  Bước 1: Tính sẵn các giai thừa xuôi và giai thừa nghịch đảo (nếu cần)
-  Bước 2: Áp dụng công thức toán để tạo ra Ckn
  
```cpp
vector<long long> a(n); // chiều xuôi
vector<long long> inv(n); // nghịch đảo

void precompute()
{
     a[0] = 1;
     inv[0] = 1;

     for (int i = 1; i < n; i++)
     {
          a[i] = (a[i - 1] * i) % m;
          inv[i] = binpow(a[i], m - 2); // Nếu m là số nguyên tố
     }
}
// Theo công thức buổi trước
```

```cpp
vector<long long> a(n); // chiều xuôi
vector<long long> inv(n); // nghịch đảo

void precompute()
{
     a[0] = 1;
     inv[0] = 1;

     for (int i = 1; i < n; i++)
          a[i] = (a[i - 1] * i) % m;
     
     inv[n - 1] = binpow(a[n - 1], m -2);
     for(int i = n - 2; i >= 0; --i)
          inv[i] = (inv[i + 1] * (i + 1)) % m;

}
// Tính ngược lại
```


## Chia để trị

**Chia để trị** là chiến lược xử lý bài toán lớn, phức tạp bằng cách chia nó thành các bài toán con nhỏ hơn. 

**Chia để trị** sẽ liên tục chia bài toán thành các thành phần nhỏ hơn cho tới một mức đủ nhỏ để giải, sau đó gộp lại kết quả của các bài toán nhỏ để cho ra lời giải của bài toán lớn.

Như vậy chia để trị sẽ có 3 phần
- **Chia:**
  -  Chia bài toán lớn ban đầu thành nhiều bài toán con nhỏ hơn. Các bài toán con này phải có tính chất và cấu trúc giống hệt bài toán gốc, chỉ khác là kích thước dữ liệu nhỏ hơn.
  - Ví dụ: Muốn sắp xếp một mảng 1000 phần tử, ta chặt nó ra làm hai mảng 500 phần tử.
- **Trị (Conquer):**
  - Giải quyết các bài toán con đó một cách độc lập.
  - Thông thường, bước này được thực hiện bằng cách gọi đệ quy (recursion). Quá trình chia sẽ liên tục diễn ra cho đến khi chạm tới trường hợp cơ sở (base case) — tức là bài toán đã đủ nhỏ để giải trực tiếp mà không cần chia thêm 
  - **Ví dụ:** mảng chỉ có 1 phần tử thì nghiễm nhiên đã được sắp xếp.
- **Kết hợp (Combine):** Gộp lời giải của các bài toán con lại để cho kết quả của bài toán lớn.

## Bài toán ký tự trong xâu được sinh theo công thức

**[Bài mẫu 1](https://code.ptit.edu.vn/student/question/DSA04005)** và **[lời giải](https://onecompiler.com/cpp#draft-easq)**

Cho dạng bài là một xâu/cáu hình được dựng lên từ 2 hoặc 3 cấu hình trước đó. Tìm phần tử/ký tự thứ k

Cần phải nhớ:
- Tính trước độ dài của tất cả các xâu, số, cấu hình.
- So sánh k với độ dài của các xâu, số nhỏ hơn để quyết định sẽ giảm nhỏ bài toán như thế nào
- Khi n và k đủ nhỏ, kết luận được k.

## Nhân ma trận và n-th Fibonacci

$$
\begin{pmatrix} F_{n+1} & F_{n} \\ F_{n} & F_{n-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^n
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
    long long mat[2][2];
    
    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    }
    
    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix a, long long n) {
    Matrix res;
    res.mat[0][0] = 1; res.mat[1][1] = 1; 
    
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

long long getFibonacci(long long n) {
    if (n == 0) return 0;
    
    Matrix base;
    base.mat[0][0] = 1; base.mat[0][1] = 1;
    base.mat[1][0] = 1; base.mat[1][1] = 0;
    
    Matrix res = binpow(base, n - 1);
    return res.mat[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    while (cin >> n) {
        cout << getFibonacci(n) << "\n";
    }
    
    return 0;
}
```

## Merge Sort và đếm số nghịch thế

**Merge Sort**

Thay vì trực tiếp sắp xếp mảng lớn, ta sẽ chia mảng lớn thành hai mảng con và thực hiện sắp xếp các mảng con đấy **(Chia)**

Khi mảng chỉ còn đúng một phần tử thì nó đã được coi là sắp xếp **(Trị)**

Gộp các mảng  con lại bằng cách sử dụng hai con trỏ Two pointer **(Combine)**

[Visualizer](https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/)

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Hàm trộn hai nửa mảng đã sắp xếp: arr[left..mid] và arr[mid+1..right]
void merge(vector<int> &arr, int left, int mid, int right)
{
     int n1 = mid - left + 1;
     int n2 = right - mid;

     // Tạo các mảng tạm thời
     vector<int> L(n1), R(n2);

     // Sao chép dữ liệu vào mảng tạm
     for (int i = 0; i < n1; i++)
          L[i] = arr[left + i];
     for (int j = 0; j < n2; j++)
          R[j] = arr[mid + 1 + j];

     // Gộp hai mảng L và R lại vào arr
     int i = 0, j = 0, k = left;
     while (i < n1 && j < n2)
     {
          if (L[i] <= R[j])
          {
               arr[k] = L[i];
               i++;
          }
          else
          {
               arr[k] = R[j];
               j++;
          }
          k++;
     }

     // Sao chép các phần tử còn lại của L (nếu có)
     while (i < n1)
     {
          arr[k] = L[i];
          i++;
          k++;
     }

     // Sao chép các phần tử còn lại của R (nếu có)
     while (j < n2)
     {
          arr[k] = R[j];
          j++;
          k++;
     }
}

// Hàm đệ quy sắp xếp trộn
void mergeSort(vector<int> &arr, int left, int right)
{
     if (left >= right)
          return; // Trường hợp cơ sở: Mảng có 1 hoặc 0 phần tử

     int mid = left + (right - left) / 2; // Tìm điểm chính giữa để tránh tràn số học

     mergeSort(arr, left, mid);      // Sắp xếp nửa đầu
     mergeSort(arr, mid + 1, right); // Sắp xếp nửa sau

     merge(arr, left, mid, right); // Trộn hai nửa đã sắp xếp
}

int main()
{
     vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

     mergeSort(arr, 0, arr.size() - 1);

     for (int x : arr)
     {
          cout << x << " ";
     }
     // Output: 3 9 10 27 38 43 82

     return 0;
}
```

**Nghịch thế**

Một cặp số trong mảng được coi là nghịch thế nếu như **số có thứ tự nhỏ hơn có giá trị lớn hơn**.

**Ví dụ:** 1 2 3 **8** 5 6 **7** có (8, 7) là một cặp nghịch thế.

Khi sắp xếp bằng MergeSort, tại thao tác Combine, bạn có thể trực tiếp so sánh để tìm ra số cặp nghịch thế này.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
     int i = left;
     int j = mid + 1;
     int k = left;
     long long inv_count = 0;

     while (i <= mid && j <= right)
     {
          if (arr[i] <= arr[j])
               temp[k++] = arr[i++];
          else
               temp[k++] = arr[j++];
          inv_count += (mid - i + 1);
     }

     while (i <= mid)
          temp[k++] = arr[i++];

     while (j <= right)
          temp[k++] = arr[j++];

     for (i = left; i <= right; i++)
          arr[i] = temp[i];

     return inv_count;
}

long long mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
     long long inv_count = 0;
     if (left < right)
     {
          int mid = left + (right - left) / 2;

          inv_count += mergeSortAndCount(arr, temp, left, mid);
          inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
          inv_count += mergeAndCount(arr, temp, left, mid, right);
     }
     return inv_count;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     vector<int> temp(n);
     cout << mergeSortAndCount(arr, temp, 0, n - 1) << "\n";

     return 0;
}
```

## Stack/Queue

**Stack** là cấu trúc dữ liệu ngăn xếp, có hai thao tác chính là **push** và **pop**.
- Hoạt động theo cơ chế LIFO - Vào sau ra trước.
- Phần tử đứng đầu đỉnh là `.top()`
- Thường được áp dụng trong các bài dãy ngoặc đúng, hình vuông/chữ nhật lớn nhất, đường đi, biến đổi trung tiền hậu tố ...

**Queue** là cấu trúc dữ liệu hàng đợi, cũng có hai thao t ác chính là **push** và **pop**
- Hoạt động theo FIFO - Vào trước ra trước
- Phần tử đứng đàu hàng đợi là `.front()`
- Thường áp dụng trong các bài có hàng đợi, tìm đường đi ngắn nhất, loang, ...


# Nội dung khác

- DFS/BFS trong đồ thị (QuickReview)
- Kiểm tra đường đi/Đường đi ngắn nhất (DFS/BFS)
- Di chuyển trong ma trận

