#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y)
{
  string s1, s2;
  s1 = toBinary(x);
  s2 = toBinary(y);
  int len = max(s1.size(), s2.size());
  if (s1.size() < len)
    s1.append(len - s1.size(), '0');
  if (s2.size() < len)
    s2.append(len - s2.size(), '0');
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (s1[i] == s2[i])
      count++;
  }
  return count;
}
string toBinary(int num)
{
  string s;
  int temp;
  while (num != 0)
  {
    temp = num % 2;
    num /= num;
    s = s + (char)num;
  }
  return s;
}