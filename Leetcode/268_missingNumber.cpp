#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
  int len = nums.size();
  sort(nums.begin(), nums.end());
  for (int i = 0; i < len; i++)
  {
    if (nums[i] != i)
      return i;
  }
  return len;
}