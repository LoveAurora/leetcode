#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> res(2, -1);
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (nums[mid] < target)
      {
        left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else if (nums[mid] == target)
      {
        int i = mid, j = mid;
        while (i >= 0 && nums[i] == target)
          i--;
        while (j <= nums.size() - 1 && nums[j] == target)
          j++;
        res[0] = i + 1;
        res[1] = j - 1;
        break;
      }
    }
    return res;
  }
};

int main()
{
  vector<int> res = {5, 7, 7, 8, 8, 10};
  Solution sol;
  cout << sol.searchRange(res, 8)[0] << sol.searchRange(res, 8)[1];
  return 0;
}