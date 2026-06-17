#include <bits/stdc++.h>
using namespace std;

void solve()
{
     int n;
     cin >> n;

     vector<int> a(n);
     for (int i = 0; i < n; i++)
          a[i] = i + 1;

     do
     {
          for (int i = 0; i < n; i++)
               cout << a[i] << " ";
          cout << endl;
     } while (next_permutation(a.begin(), a.end()));
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     solve();
}