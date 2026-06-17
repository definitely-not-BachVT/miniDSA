#include <bits/stdc++.h>
using namespace std;

int n;
void sinh(string x)
{
     if (x.size() == n)
     {
          cout << x << "\n";
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
}