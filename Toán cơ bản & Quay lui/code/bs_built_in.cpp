#include <bits/stdc++.h>
using namespace std;

int main()
{
     int x;
     cin >> x;

     vector<int> arr = {10, 25, 32, 45, 50, 68, 77, 89, 95};

     // Tìm xem có tồn tại số x trong mảng không
     if (binary_search(arr.begin(), arr.end(), x))
          cout << "ton tai\n";
     else
          cout << "khong ton tai\n";

     // lower_bound => Tìm số đầu tiên trong mảng lớn hơn hoặc bằng x
     // trả về ITERATOR

     int chiso = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
     cout << chiso << "\n";

     // upper_bound => Tìm số đầu tiên trong mảng lớn hơn hẳn x
     // trả về ITERATOR

     int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
     cout << idx << "\n";
}