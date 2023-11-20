#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int dp[m][n];
    // dp[m][n] = dp[m-1][n]+dp[m][n-1];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == 0 && j == 0)
        {
          dp[0][0] = grid[0][0];
        }
        else if (i == 0)
        {
          dp[i][j] = grid[i][j] + dp[i][j - 1];
        }
        else if (j == 0)
        {
          dp[i][j] = grid[i][j] + dp[i - 1][j];
        }
        else
        {
          dp[i][j] = min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
int main()
{
  Solution sol;
}