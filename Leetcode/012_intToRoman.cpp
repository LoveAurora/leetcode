#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string intToRoman(int num)
  {
    string str;
    vector<pair<int, string>> v = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    while (num > 0)
    {
      // for (auto iter = m.begin(); iter != m.end(); iter++)
      // {
      //   if (num > iter->first)
      //   {
      //     str += iter->second;
      //     num -= iter->first;
      //     break;
      //   }
      for (auto kv : v)
      {
        cout << kv.first << endl;
        if (num >= kv.first)
        {
          str += kv.second;
          num -= kv.first;
          break;
        }
      }
    }
    return str;
  }
};

int main()
{

  Solution sol;
  cout << sol.intToRoman(9);
}