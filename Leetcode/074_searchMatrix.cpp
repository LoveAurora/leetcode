#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      int midValue = matrix[mid / n][mid % n];
      if (midValue < target)
      {
        left = mid + 1;
      }
      else if (midValue > target)
      {
        right = mid - 1;
      }
      else
        return true;
    }
    return false;
  }
};
int main()
{
  vector<vector<int>> givenMatrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution sol;
  cout << sol.searchMatrix(givenMatrix, 3);
  return 0;
}