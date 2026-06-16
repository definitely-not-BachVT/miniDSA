
#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n, k;
     cin >> n >> k;

     // cấu hình đầu: 123 => 11100 hay là cấu hình cuối của ....
     // cấu hình cuối: 345 => 00111 hay là cấu hình cuối của ...

     vector<int> p(n, 0);
     for (int i = 0; i < k; ++i)
          p[i] = 1;

     do
     {
          for (int i = 0; i < n; ++i)
               if (p[i] == 1)
                    cout << i + 1 << " ";
          cout << "\n";
     } while (prev_permutation(p.begin(), p.end()));
}

// Copilot => Trường cấm không cho dùng. Phát bởi CodePTIT Client
// Intellisense => Không bị cấm, dùng thôi