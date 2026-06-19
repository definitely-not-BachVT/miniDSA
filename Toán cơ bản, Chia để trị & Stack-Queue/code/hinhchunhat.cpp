#include <bits/stdc++.h>
using namespace std;

int baitoan(vector<int> &a, int m)
{
     vector<int> left(m, -1);
     vector<int> right(m, m);

     stack<int> st;
     for (int i = 0; i < m; ++i)
     {
          while (!st.empty() && a[st.top()] >= a[i])
               st.pop();

          if (st.empty())
               left[i] = -1;
          else
               left[i] = st.top();

          st.push(i);
     }

     while (!st.empty())
          st.pop();

     for (int i = m - 1; i >= 0; --i)
     {
          while (!st.empty() && a[st.top()] >= a[i])
               st.pop();

          if (st.empty())
               right[i] = m;
          else
               right[i] = st.top();

          st.push(i);
     }

     int mx = 0;
     for (int i = 0; i < m; ++i)
          mx = max(mx, (right[i] - left[i] - 1) * a[i]);

     return mx;
}

void solve()
{
     int n, m;
     cin >> n >> m;

     vector<vector<int>> a(n, vector<int>(m, 0));

     for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
               cin >> a[i][j];

     int ans = 0;
     vector<int> level(m, 0);
     for (int i = 0; i < n; ++i)
     {
          for (int j = 0; j < m; ++j)
               if (a[i][j])
                    level[j]++;
               else
                    level[j] = 0;

          ans = max(ans, baitoan(level, m));
     }

     cout << ans << "\n";
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     while (t--)
          solve();
}