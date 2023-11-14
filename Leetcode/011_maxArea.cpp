#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int left = 0, right = height.size() - 1, area = 0, maxarea = 0;
    while (left < right)
    {
      if (height[left] <= height[right])
      {
        area = (right - left) * height[left];
        left++;
      }
      else
      {
        area = (right - left) * height[right];
        right--;
      }
      maxarea = max(maxarea, area);
    }
    return maxarea;
  }
};
int main()
{
  vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sol;
  cout << sol.maxArea(v);
}
