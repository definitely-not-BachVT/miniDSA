#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
     int temp;
     while (a != 0)
     {
          temp = a;
          a = b % a;
          b = temp;
     }
     return b;
}

int lcm(int a, int b)
{
     return a / gcd(a, b) * b;
}

int main()
{
     int a, b;
     cin >> a >> b;
}