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

     int n;
     cin >> n;

     cout << n << " duoc phan tich thanh\n";
     for (int i = 2; i * i <= n; ++i)
          if (n % i == 0)
          {
               cout << "so nguyen to: " << i;

               int cnt = 0;
               while (n % i == 0)
               {
                    n /= i;
                    ++cnt;
               }

               cout << " voi so bac la: " << cnt << "\n";
          }

     if (n > 1)
          cout << "so nguyen to " << n << "voi so bac la 1\n";
}