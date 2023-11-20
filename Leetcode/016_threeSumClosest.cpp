#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // 二分查找函数，返回与目标值最接近的数组下标
  int binarySearchClosest(const std::vector<int> &array, int target)
  {
    int left = 0;
    int right = array.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      // 如果中间元素等于目标值，则直接返回索引
      if (array[mid] == target)
        return mid;
      // 如果中间元素小于目标值，在右半部分继续查找
      else if (array[mid] < target)
        left = mid + 1;
      // 如果中间元素大于目标值，在左半部分继续查找
      else
        right = mid - 1;
    }
    // 如果未找到目标值，找到最接近的元素
    if (left >= array.size())
      return array.size() - 1; // 如果目标值大于数组中的所有元素，则返回最后一个元素的索引
    else if (right < 0)
      return 0; // 如果目标值小于数组中的所有元素，则返回第一个元素的索引
    else
      // 比较左右两侧哪个更接近目标值，返回索引
      return abs(array[left] - target) < abs(array[right] - target) ? left : right;
  }
  int threeSumClosest(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int temp, best = INT32_MAX;
    for (int i = 0; i < nums.size() - 2; i++)
    {
      int left = i + 1, right = nums.size() - 1;
      while (left < right)
      {
        temp = nums[left] + nums[right] + nums[i];
        best = abs(temp - target) < abs(best - target) ? temp : best;
        if (temp < target)
          left++;
        else if (temp > target)
          right--;
        else
          return temp;
      }
    }
    return best;
  }
};

int main()
{
  vector<int> nums = {-1, 2, 1, -4};
  Solution sol;
  cout << sol.threeSumClosest(nums, 1);
}