#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
     long long a[2][2];

     void set0()
     {
          a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
     }

     void unit()
     {
          set0();
          a[0][0] = a[1][1] = 1;
     }

     void init()
     {
          a[0][0] = a[0][1] = a[1][0] = 1;
          a[1][1] = 0;
     }

     Matrix operator*(const Matrix &other) const
     {
          Matrix ans;
          ans.set0();

          for (int i = 0; i < 2; ++i)
               for (int j = 0; j < 2; ++j)
                    for (int k = 0; k < 2; ++k)
                         ans.a[i][j] = (ans.a[i][j] + (a[i][k] * other.a[k][j]) % MOD) % MOD;

          return ans;
     }
};

Matrix binPow(Matrix a, long long b)
{
     Matrix ans;
     ans.unit();

     while (b)
     {
          if (b % 2)
               ans = ans * a;
          a = a * a;
          b /= 2;
     }
     return ans;
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

          if (n == 0)
          {
               cout << "0\n";
               continue;
          }

          Matrix a;
          a.init();

          Matrix ans = binPow(a, n - 1);
          cout << ans.a[0][0] << "\n";
     }
}