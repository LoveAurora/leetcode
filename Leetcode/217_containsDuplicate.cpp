#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
      if (m[nums[i]] == 1)
        return true;
      else
        m[nums[i]] = 1;
    }
    return false;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4};
  Solution sol;
  sol.containsDuplicate(nums);
  return 0;
}