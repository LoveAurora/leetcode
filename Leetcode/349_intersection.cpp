#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> result_set;                           // 存放结果，使用set是为了去重
    unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 注意这个赋值方法可以进行容器转换！

    for (int num : nums2)
    {
      if (nums_set.find(num) != nums_set.end())
      {
        result_set.insert(num);
      }
    }
    return vector<int>(result_set.begin(), result_set.end()); // 注意这个给赋值方法！
  }
};

int main()
{
  return 0;
}