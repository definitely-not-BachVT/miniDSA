#include <bits/stdc++.h>
using namespace std;

vector<int> curr;
void backtrack(int n, int mx)
{
     if (n == 0)
     {
          cout << "(";
          int size = curr.size();
          for (int i = 0; i < size; ++i)
          {
               cout << curr[i];
               if (i != size - 1)
                    cout << " ";
          }
          cout << ") ";
          return;
     }

     for (int i = mx; i >= 1; --i)
          if (i <= n)
          {
               curr.push_back(i);
               backtrack(n - i, i);
               curr.pop_back();
          }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;

          backtrack(n, n);
          cout << "\n";
     }
}