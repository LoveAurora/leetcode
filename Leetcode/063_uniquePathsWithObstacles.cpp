#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[m][n];
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;
    // dp[m][n] = dp[m-1][n]+dp[m][n-1];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == 0 && j == 0)
        {
          dp[0][0] = 1;
        }
        else if (i == 0)
        {
          if (obstacleGrid[i][j - 1] == 1)
          {
            obstacleGrid[i][j] = 1;
            dp[i][j] = 0;
          }
          else
          {
            dp[i][j] = dp[i][j - 1];
          }
        }
        else if (j == 0)
        {
          if (obstacleGrid[i - 1][j] == 1)
          {
            obstacleGrid[i][j] = 1;
            dp[i][j] = 0;
          }
          else
            dp[i][j] = dp[i - 1][j];
        }
        else
        {
          if (obstacleGrid[i - 1][j] != 1 && obstacleGrid[i][j - 1] != 1)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          else if (obstacleGrid[i - 1][j] != 1)
            dp[i][j] = dp[i - 1][j];
          else if (obstacleGrid[i][j - 1] != 1)
            dp[i][j] = dp[i][j - 1];
          else
            dp[i][j] = 0;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
int main()
{
}