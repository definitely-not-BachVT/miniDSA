#include <bits/stdc++.h>
using namespace std;
void solve()
{
     int n, k;
     cin >> n >> k;

     vector<int> bit(n, 0);
     for (int i = 0; i < k; i++)
     {
          bit[i] = 1;
     }

     do
     {
          for (int i = 0; i < n; i++)
          {
               if (bit[i] == 1)
               {
                    cout << i + 1 << " ";
               }
          }
          cout << endl;
     } while (prev_permutation(bit.begin(), bit.end()));
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     solve();
}