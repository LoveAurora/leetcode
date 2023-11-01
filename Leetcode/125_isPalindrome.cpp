#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
bool isPalindrome(string s)
{
  // 移除非字母字符
  s.erase(remove_if(s.begin(), s.end(), [](char c)
                    { return !isalnum(c); }),
          s.end());
  // 将大写字母转换为小写字母
  transform(s.begin(), s.end(), s.begin(), [](char c)
            { return tolower(c); });
  int len = s.size();
  if (len == 0 || len == 1)
    return true;
  for (int i = 0; i <= len / 2; i++)
  {
    if (s.at(i) != s.at(len - i - 1))
      return false;
  }
  return true;
}

int main()
{
}