#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    multimap<int, int> m;
    vector<int> v = {-1, -1};
    for (int k = 0; k < static_cast<int>(nums.size()); k++)
    {
      m.insert({nums[k], k});
    }
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
      if (nums[i] + nums[j] < target)
        i++;
      else if (nums[i] + nums[j] > target)
        j--;
      else
      {
        auto range = m.equal_range(nums[i]);
        for (auto it = range.first; it != range.second; ++it)
        {
          if (it->second != i) // 排除相同索引
          {
            v[0] = it->second;
            v[1] = i;
            return v;
          }
        }
        break;
      }
    }
    return v;
  }
};

int main()
{
  vector<int> nums = {3, 3};
  int target = 6;
  vector<int> v;
  Solution sol;
  v = sol.twoSum(nums, target);
  cout << v[0] << " " << v[1];
  return 0;
}
