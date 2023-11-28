#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int i = nums.size() - 2;

    // 扫描第一遍，找到一个符合nums[i]<nums[i+1]，因为...xy...一定小于...yx...
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
      i--;
    }
    // 第二遍扫描，确保是没有一个序列小于现在这个序列大于原始序列
    // 当i<0时，说明原始序列是一个递减序列, 直接reverse(nums.begin(), nums.end());
    // 当i>=0时，从最后一个数往前找一个大于nums[i]的数字，y左边的数字一定是小于y的但是有可能大于x
    // 第二次循环就是找一个大于nums[i]的数，交换后左边部分一定比原来大一点，右边的递减序列一定比原来小一点
    // 然后把右边部分的reverse一下就是最小的递减序列了
    if (i >= 0)
    {
      int j = nums.size() - 1;
      while (j > i && nums[j] <= nums[i])
        j--;
      swap(nums[j], nums[i]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
int main()
{
  vector<int> nums = {1, 3, 2};
  Solution sol;
  sol.nextPermutation(nums);
  for (auto num : nums)
  {
    cout << num;
  }
  return 0;
}