#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
  }
  void backtrack(vector<vector<int>> &res, vector<int> &nums, int first, int end)
  {
    if (first == end)
    {
      res.emplace_back(nums);
      return;
    }
    for (int i = first; i < nums.size(); i++)
    {
      swap(nums[i], nums[first]);
      backtrack(res, nums, first + 1, end);
      swap(nums[i], nums[first]);
    }
  }
};
int main()
{
  return 0;
}