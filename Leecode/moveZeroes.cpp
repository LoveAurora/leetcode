#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
  int i = 0, j = 0;
  int left = 0, right = 0;
  int len = nums.size();
  while (right < len)
  {
    if (nums[right])
    {
      swap(nums[right], nums[left]);
      left++;
    }
    right++;
  }

  vector<int> v;
  for (int i = 0; i < len; i++)
  {
    if (nums[i] != 0)
      v.push_back(nums[i]);
  }
  j = len - v.size();
  for (int i = 0; i < j; i++)
  {
    v.push_back(0);
  }
  nums = v;
}
int main()
{
  vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroes(nums);
  for (int i : nums)
  {
    cout << i << " ";
  }
}