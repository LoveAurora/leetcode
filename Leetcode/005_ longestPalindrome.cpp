#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string longestPalindrome(string s)
  {
    string str;
    // 中心扩展算法
    // 从每一个位置mid出发，向两边扩散
    int maxLeft = 0;  // 记录最长回文子串的起点
    int maxRight = 0; // 记录最长回文子串的终点
    int maxLen = 0;   // 记录最长回文子串的长度
    int n = s.size(), len = 1;
    for (int mid = 0; mid < n; mid++)
    {
      int left = mid - 1;
      int right = mid + 1;
      while (left >= 0 && s[left] == s[mid])
      { // 向左侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
        left--;
        len++;
      }
      while (right < n && s[right] == s[mid])
      { // 向右侧扩展，直到超过边界或遇到与中心字符不等跳出while循环
        right++;
        len++;
      }
      while (left >= 0 && right < n && s[left] == s[right])
      { // 最后一次循环中，即最长回文子串索引为：i~j，此时的left=i-1，right=j+1
        // 在确保left >= 0和right < n之前就检查了s[left] == s[right]。如果left变为负值或right超出字符串范围，
        // 访问s[left]或s[right]将导致未定义行为，从而引发运行时错误。while里面的条件判断顺序很重要
        left--;
        right++;
        len += 2;
      }
      if (maxLen < len)
      {
        maxLeft = left;
        maxRight = right;
        maxLen = len;
      }
      len = 1;
    }
    return s.substr(maxLeft + 1, maxLen);
  }
};
int main()
{
  string s = "abcba";
  Solution sol;
  cout << sol.longestPalindrome(s);
}
