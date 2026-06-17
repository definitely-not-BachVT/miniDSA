
#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n, k;
     cin >> n >> k;

     vector<int> p(n, 0);
     for (int i = 0; i < k; ++i)
          p[i] = 1;

     do
     {
          int tong = 0;

          for (int i = 0; i < n; ++i)
               if (p[i] == 1)
                    tong += i + 1;

          if (tong % 2)
          {
               for (int i = 0; i < n; ++i)
                    if (p[i] == 1)
                         cout << i + 1 << " ";
               cout << "\n";
          }

     } while (prev_permutation(p.begin(), p.end()));
}
