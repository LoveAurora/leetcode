#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findComplement(int num)
{
  int i;
  for (i = 0; i < INT_MAX; i++)
  {
    if (pow(2, i) <= num && num < pow(2, i + 1))
      break;
  }
  return pow(2, i + 1) - num - 1;
}
int main()
{
  cout << findComplement(5);
}