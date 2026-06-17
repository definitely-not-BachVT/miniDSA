#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n, k;
     cin >> n >> k;

     string s(n, '0');
     for (int i = n - k; i < n; i++)
          s[i] = '1';

     do
     {
          cout << s << endl;
     } while (next_permutation(s.begin(), s.end()));
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     solve();
}