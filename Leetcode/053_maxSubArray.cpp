#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int len = nums.size();
    vector<int> dp(len);
    dp[0] = nums[0];
    int max = dp[0];
    for (int i = 1; i < len; i++)
    {
      if (dp[i - 1] < 0)
        dp[i] = nums[i];
      else
        dp[i] = dp[i - 1] + nums[i];
      max = max > dp[i] ? max : dp[i];
    }
    return max;
  }
};
