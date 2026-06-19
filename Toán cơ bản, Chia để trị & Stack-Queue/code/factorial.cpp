#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long fact[20];
long long inv[20];

long long binpow(long long a, long long b)
{
     a %= MOD;
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

void precompute()
{
     fact[0] = 1;
     inv[0] = 1;

     for (int i = 1; i < 20; ++i)
          fact[i] = i * fact[i - 1] % MOD;

     inv[19] = binpow(fact[19], MOD - 2);
     for (int i = 18; i >= 1; --i)
          inv[i] = (i + 1) * inv[i + 1] % MOD;
}

int main()
{
     long long a, b;
     cin >> a >> b;
}