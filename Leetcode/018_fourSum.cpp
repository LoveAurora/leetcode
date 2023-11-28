#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 比较难理解的就是数组去重
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> res;
    int len = nums.size();
    if (len < 4)
      return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      // 检查当前的 nums[i] 是否与前一个元素 nums[i - 1] 相等，并且确保 i 大于 0。如果相等，说明当前的 nums[i] 已经在之前的组合中处理过了，为了避免重复，使用 continue 跳过本次循环，直接进入下一次循环。
      if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        break;
      if ((long)nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
        continue;

      for (int j = i + 1; j < len - 2; j++)
      {

        if (j > 0 && nums[j] == nums[j - 1])
          continue;
        // 检查当前的 nums[j] 是否与前一个元素 nums[j - 1] 相等，并且确保 i 大于 0。如果相等，说明当前的 nums[i] 已经在之前的组合中处理过了，为了避免重复，使用 continue 跳过本次循环，直接进入下一次循环。
        if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
          break;
        if ((long)nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target)
          continue;
        int left = j + 1, right = len - 1;
        while (left < right)
        {
          long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target)
          {
            right--;
          }
          else if (sum < target)
          {
            left++;
          }
          else
          {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1])
              left++; // 避免数组重复
            left++;
            while (left < right && nums[right] == nums[right - 1])
              right--; // 避免数组重复
            right--;
          }
        }
      }
    }
    return res;
  }
};

int main()
{
  return 0;
}
