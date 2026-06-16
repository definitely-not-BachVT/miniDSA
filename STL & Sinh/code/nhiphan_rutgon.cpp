
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

// Để n và ans ở trên cùng để không phải
// truyền vào hàm mà vẫn dùng được

void sinh(string x)
{
     if (x.size() == n)
     {
          ans.push_back(x);
          return;
     }

     sinh(x + "0");
     sinh(x + "1");
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     cin >> n;
     sinh("");

     for (string x : ans)
          cout << x << "\n";
}