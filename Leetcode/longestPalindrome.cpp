#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(string s)
{
  int len = s.size();
  int maxnum;
  map<char, int> m;
  if (len == 1)
    return 1;
  for (int i = 0; i < len; i++)
    m[s[i]]++;
  for (const auto &pair : m)
  {
    if (len % 2 == 0)
      maxnum += pair.second / 2;
    else
      maxnum += pair.second / 2;
  }
  for (const auto &pair : m)
  {
    if (pair.second % 2)
      maxnum += 1;
  }
  return maxnum;
}