#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isHappy(int n)
  {
    set<int> s;
    while (n != 1)
    {
      int temp = 0;
      while (n != 0)
      {
        temp += pow(n % 10, 2);
        n = n / 10;
      }
      if (s.find(temp) == s.end())
      {
        s.insert(temp);
        n = temp;
      }
      else
        return false;
    }
    return true;
  }
};
int main()
{
  Solution sol;
  cout << sol.isHappy(19);
}
