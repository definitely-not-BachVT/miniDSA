#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> gray(11, vector<string>());
void sinh()
{
     gray[1] = {"0", "1"};
     for (int i = 2; i < 11; ++i)
     {
          int sz = pow(2, i - 1);
          for (int j = 0; j < sz; ++j)
               gray[i].push_back("0" + gray[i - 1][j]);
          for (int j = sz - 1; j >= 0; --j)
               gray[i].push_back("1" + gray[i - 1][j]);
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int t;
     cin >> t;

     sinh();

     while (t--)
     {
          int n;
          cin >> n;

          for (string x : gray[n])
               cout << x << " ";
          cout << "\n";
     }
}