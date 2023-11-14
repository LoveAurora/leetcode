#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
  int romanToInt1(string s)
  {
    int num = 0, i = 0;
    map<string, int> m = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}};

    while (i < s.size())
    {
      if (m.find(s.substr(i, 2)) != m.end())
      {
        cout << s.substr(i, 2) << endl;
        num += m[s.substr(i, 2)];
        i += 2;
      }
      else
      {
        cout << s.substr(i, 1) << endl;
        num += m[s.substr(i, 1)];
        i++;
      }
    }
    return num;
  }
  int romanToInt2(string s)
  {
    map<char, int> m = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}};
    int res = 0, i;
    for (i = 0; i < s.size() - 1; i++)
    {
      if (m[s[i]] >= m[s[i + 1]])
      {
        res += m[s[i]];
      }
      else
      {
        res -= m[s[i]];
      }
    }
    res += m[s[i]];
    return res;
  }
};

int main()
{
  Solution sol;
  cout << sol.romanToInt2("MCMXCIV") << endl;
  return 0;
}
