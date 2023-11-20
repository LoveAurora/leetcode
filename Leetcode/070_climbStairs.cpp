#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1 || n == 2)
      return n;
    int a = 1;
    int b = 2;
    int num = 0;
    for (int i = 3; i <= n; i++)
    {
      num = a + b;
      a = b;
      b = num;
    }
    return num;
  }
};