#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arrangeCoins(int n)
{
  long long temp1, temp;
  if (n == 1)
    return 1;
  for (int i = 1; i < INT_MAX; i++)
  {
    temp1 = i * (i + 1) / 2;
    temp = (int)temp1;
    if (temp == n || (temp < n && n < temp + i + 1))
      return i;
    else if (temp < n && n == temp + i + 1)
      return i + 1;
  }
  return 0;
}
int main()
{
  cout << arrangeCoins(5) << " ";
}