
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ketqua;

// Để n và ketqua ở trên cùng để không phải
// truyền vào hàm mà vẫn dùng được

void sinh(string hientai)
{
     if (hientai.size() == n)
     {
          ketqua.push_back(hientai);
          return;
     }

     string them0 = hientai + "0";
     string them1 = hientai + "1";

     sinh(them0);
     sinh(them1);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     cin >> n;

     string batdau = "";
     sinh(batdau);

     for (string x : ketqua)
          cout << x << "\n";
}