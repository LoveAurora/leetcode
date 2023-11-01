#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int majorityElement(vector<int> &nums)
{
  int len = nums.size();
  sort(nums.begin(), nums.end());
  return nums[len / 2];
}

int main()
{
  vector<int> nums = {3, 2, 3};
  int c = majorityElement(nums);
  cout << c << endl;
}