#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int m = triangle.size(), minnum = 100000000;
    vector<vector<int>> dp(m, vector<int>(m, 0));
    if (m == 1)
      return triangle[0][0];
    dp[0][0] = triangle[0][0];
    dp[0].resize(1);
    for (int i = 1; i < m; i++)
    {
      dp[i].resize(i + 1);
      for (int j = 0; j <= i; j++)
      {
        if (j == 0)
          dp[i][j] = dp[i - 1][j] + triangle[i][j];
        else if (j == i)
          dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        else
          dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
    }
    for (int i = 0; i < m; i++)
    {
      minnum = min(dp[m - 1][i], minnum);
    }
    return minnum;
  }
};
int main()
{
  vector<vector<int>> v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  Solution sol;
  cout << sol.minimumTotal(v);
}
