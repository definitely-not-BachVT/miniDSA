/*
---STATEMENT---

Cho mảng a gồm n phần tử
Kiểm tra xem có tập con nào của mảng a có tổng các phần tử bằng k không?
(2 <= n <= 40)

---INPUT/OUTPUT FORMAT---

Nhập vào số nguyên n và k
Dòng tiếp theo là n phần tử của mảng a

YES nếu có thể tạo
NO nếu không thể tạo

-------------------
*/

#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
vector<long long> leftPart;
vector<long long> rightPart;

void sinh1(vector<long long> &left, long long curr, int idx)
{
     if (idx == n / 2)
     {
          leftPart.push_back(curr);
          return;
     }

     sinh1(left, curr + left[idx], idx + 1);
     sinh1(left, curr, idx + 1);
}

void sinh2(vector<long long> &right, long long curr, int idx)
{
     if (idx == n - n / 2)
     {
          rightPart.push_back(curr);
          return;
     }

     sinh2(right, curr + right[idx], idx + 1);
     sinh2(right, curr, idx + 1);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     cin >> n >> k;

     vector<long long> a(n);
     for (int i = 0; i < n; ++i)
          cin >> a[i];

     vector<long long> left(n / 2);
     vector<long long> right(n - n / 2);

     for (int i = 0; i < n / 2; ++i)
          left[i] = a[i];
     for (int i = 0; i < n - n / 2; ++i)
          right[i] = a[i + n / 2];

     sinh1(left, 0, 0);
     sinh2(right, 0, 0);

     sort(rightPart.begin(), rightPart.end());

     bool found = false;
     for (long long x : leftPart)
          if (binary_search(rightPart.begin(), rightPart.end(), k - x))
          {
               found = true;
               break;
          }

     if (found)
          cout << "YES\n";
     else
          cout << "NO\n";
}