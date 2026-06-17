#include <bits/stdc++.h>
using namespace std;

bool snt(long long n)
{
     if (n == 2 || n == 3)
          return true;
     if (n < 2 || n % 2 == 0 || n % 3 == 0)
          return false;

     for (int i = 5; i * i <= n; i += 6)
          if (n % i == 0 || n % (i + 2) == 0)
               return false;

     return true;
}

int main()
{
     long long n;
     cin >> n;

     if (snt(n))
          cout << "YES\n";
     else
          cout << "NO\n";
}