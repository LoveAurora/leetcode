#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void swap(vector<int> &nums, int i, int j)
  {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void quicksort(vector<int> &nums, int i, int j)
  {
    if (i >= j)
      return;
    int left = i, right = j;
    while (left < right)
    {
      while (right > left && nums[right] >= nums[i])
        right--;
      while (right > left && nums[left] <= nums[i])
        left++;
      swap(nums, left, right);
    }
    swap(nums, i, right);
    quicksort(nums, i, right - 1);
    quicksort(nums, right + 1, j);
  }
  /* 哨兵划分 */
  int partition(vector<int> &nums, int left, int right)
  {
    // 以 nums[left] 作为基准数
    int i = left, j = right;
    while (i < j)
    {
      while (i < j && nums[j] >= nums[left])
        j--; // 从右向左找首个小于基准数的元素
      while (i < j && nums[i] <= nums[left])
        i++;            // 从左向右找首个大于基准数的元素
      swap(nums, i, j); // 交换这两个元素
    }
    swap(nums, i, left); // 将基准数交换至两子数组的分界线
    return i;            // 返回基准数的索引
  }
  /* 快速排序 */
  void quickSort(vector<int> &nums, int left, int right)
  {
    // 子数组长度为 1 时终止递归
    if (left >= right)
      return;
    // 哨兵划分
    int pivot = partition(nums, left, right);
    // 递归左子数组、右子数组
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
  }
  void sortColors(vector<int> &nums)
  {
    // int len = nums.size();
    // quicksort(nums, 0, len - 1);
    vector<int> count = {0, 0, 0};
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        count[0] += 1;
      else if (nums[i] == 1)
        count[1] += 1;
      else
        count[2] += 1;
    }
    for (int i = 0; i < count[0]; i++)
      nums[i] = 0;
    for (int i = count[0]; i < count[0] + count[1]; i++)
      nums[i] = 1;
    for (int i = count[0] + count[1]; i < nums.size(); i++)
      nums[i] = 2;
  }
};
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(nums);
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i];
  }
}
