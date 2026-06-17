#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 3;
// B1 Khởi tạo tất cả là số nguyên tố
vector<int> isPrime(MAXN, 1);
vector<int> snt;

void sieve()
{
     isPrime[0] = isPrime[1] = 0;
     for (int i = 2; i * i <= MAXN; ++i)
          if (isPrime[i])
          {
               for (int j = i * i; j < MAXN; j += i)
                    isPrime[j] = 0;
          }

     for (int i = 2; i < MAXN; ++i)
          if (isPrime[i])
               snt.push_back(i);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     sieve();

     int n;
     cin >> n;

     for (int i = 0; snt[i] * snt[i] <= n; ++i)
     {
          if (n % snt[i] == 0)
          {
               cout << snt[i] << " ";

               int cnt = 0;
               while (n % snt[i] == 0)
               {
                    ++cnt;
                    n /= snt[i];
               }

               cout << cnt << "\n";
          }
     }

     if (n > 1)
          cout << n << " 1\n";
}