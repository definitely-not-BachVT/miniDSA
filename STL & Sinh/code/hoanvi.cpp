
#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     // n = 5
     // Phần tử đầu tiên là gì? 12345
     // Hoán vị cuối cùng là: 54321

     vector<int> a(n);
     for (int i = 0; i < n; ++i)
          a[i] = i + 1;

     do
     {
          for (int i = 0; i < n; ++i)
               cout << a[i] << " ";
          cout << "\n";
     } while (next_permutation(a.begin(), a.end()));
}

// Copilot => Trường cấm không cho dùng. Phát bởi CodePTIT Client
// Intellisense => Không bị cấm, dùng thôi