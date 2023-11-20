#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int titleToNumber(string columnTitle)
  {
    int len = columnTitle.size();
    int sum = 0;
    for (int i = len - 1; i >= 0; i--)
    {
      sum = sum + pow(26, len - i - 1) * (columnTitle[i] - 64);
    }
    return sum;
  }
};
int main()
{
  cout << 'Z' - 64;
}
