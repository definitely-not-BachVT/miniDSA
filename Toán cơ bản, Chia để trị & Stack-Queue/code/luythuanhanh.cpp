#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Đệ quy
long long bp_dequy(long long a, long long b)
{
     if (b == 0)
          return 1;
     // Không nhất thiết phải có.
     if (b == 1)
          return a;

     long long half = bp_dequy(a, b / 2) % MOD;
     if (b % 2)
          return (half * half) % MOD * a % MOD;
     return half * half % MOD;
}

// Vòng lặp While
long long bp_while(long long a, long long b)
{
     a % MOD;
     long long ans = 1;
     while (b)
     {
          if (b % 2)
               ans = ans * a % MOD;
          a = a * a % MOD;
          b /= 2;
     }
     return ans;
}

int main()
{
     long long a, b;
     cin >> a >> b;
}