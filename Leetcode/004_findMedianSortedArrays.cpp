#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(), n = nums2.size();
    vector<int> v(m + n, 0);
    int j = 0, k = 0, count = 0;

    while (j < m && k < n)
    {
      if (nums1[j] < nums2[k])
      {
        v[count] = nums1[j];
        count++;
        j++;
      }
      else
      {
        v[count] = nums2[k];
        count++;
        k++;
      }
    }
    while (j < m)
    {
      v[count] = nums1[j];
      count++;
      j++;
    }
    while (k < n)
    {
      v[count] = nums2[k];
      count++;
      k++;
    }
    int index = (m + n) / 2;
    if ((m + n) % 2 == 1)
    {
      return v[index];
    }
    else
    {
      return (float)((v[index] + v[index - 1]) / 2.0f);
    }
  }
};
int main()
{
  vector<int> nums1 = {1, 2}, nums2 = {3, 4};
  Solution sol;
  cout << sol.findMedianSortedArrays(nums1, nums2);
}