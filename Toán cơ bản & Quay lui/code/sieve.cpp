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
     for (int i = 0; i < 10; ++i)
          cout << snt[i] << " ";
}