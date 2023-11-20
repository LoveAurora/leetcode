#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int dp[m][n], max;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == 0 && j == 0)
          dp[0][0] = (matrix[0][0] - '0');
        else if (i == 0)
        {
          dp[i][j]
        }
        else if (j == 0)
        {
        }
        else
        {
        }
      }
    }
  }
};
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution sol;
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i];
  }
}
