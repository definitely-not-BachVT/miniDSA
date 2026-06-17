#include <bits/stdc++.h>
using namespace std;

int n;
void sinh(string x)
{
     if (x.length() == (n + 1) / 2)
     {
          cout << x;
          for (int i = n / 2 - 1; i >= 0; i--)
               cout << x[i];
          cout << '\n';
          return;
     }

     sinh(x + "0");
     sinh(x + "1");
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     cin >> n;
     sinh("");

     return 0;
}