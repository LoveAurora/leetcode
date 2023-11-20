#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    // 获取数组的长度
    int n = nums.size();

    // 创建一个新的数组arr，并将nums的元素拷贝到arr中
    vector<int> arr = nums;

    // 对arr进行排序
    sort(arr.begin(), arr.end());
    // 计算中间值，用于重新排列数组
    int x = (n + 1) / 2;
    // 通过循环重新排列数组
    for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
    {
      // 将排序后的较小的一半元素放在奇数索引位置
      nums[i] = arr[j];
      // 如果数组长度为奇数，i+1不能越界，将排序后的较大的一半元素放在偶数索引位置
      if (i + 1 < n)
      {
        nums[i + 1] = arr[k];
      }
    }
  }
};
int main()
{
  vector<int> nums = {1, 3, 2, 2, 3, 1};
  Solution sol;
  sol.wiggleSort(nums);
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i];
  }
}