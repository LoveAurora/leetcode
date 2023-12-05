#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
  vector<int> path;
  vector<vector<int>> res;

public:
  void helper(vector<int> &nums, int begin)
  {
    res.push_back(path);
    for (int i = begin; i < nums.size(); i++)
    {
      path.push_back(nums[i]);
      helper(nums, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums)
  {
    helper(nums, 0);
    return res;
  }
};
int main()
{
  return 0;
}