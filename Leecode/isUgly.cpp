#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n)
{
  if (n < 1)
    return false;
  if (n == 1)
    return true;
  int factors[] = {2, 3, 5};

  for (int i : factors)
  {
    while (n % i == 0)
    {
      n /= i;
    }
  }
  return n == 1;
}