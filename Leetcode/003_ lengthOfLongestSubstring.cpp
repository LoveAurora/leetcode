#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int lengthOfLongestSubstring(string s) // 滑动窗口思想
  {
    int n = s.size();
    if (n == 0)
      return 0;
    int left = 0, right = 0, maxlength = 0;
    unordered_set<char> str; // 存储窗口中的字符
    while (right < n)
    {
      // 查询新的位置的字符是否在窗口里面
      if (str.find(s[right]) == str.end())
      // str.end()：这是 std::unordered_set 的成员函数，
      // 返回指向集合末尾的迭代器。在集合中没有找到元素时，迭代器指向集合的末尾。
      {
        str.insert(s[right]);
        maxlength = max(maxlength, right - left + 1);
        right++;
      }
      else
      {
        str.erase(s[left]);
        left++;
      }
    }
    return maxlength;
  }
};
int main()
{
  string s = "abcba";
  Solution sol;
  cout << sol.lengthOfLongestSubstring(s);
}