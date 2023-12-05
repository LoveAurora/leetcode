#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int maxnum = n * m, num = 0;
    vector<int> res(maxnum, 0);

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (num <= maxnum)
    {
      for (int i = left; i <= right; i++)
      {
        res[num++] = matrix[top][i];
        if (num >= maxnum)
          break;
      }
      if (num >= maxnum)
        break;
      top++;
      for (int i = top; i <= bottom; i++)
      {
        res[num++] = matrix[i][right];
        if (num >= maxnum)
          break;
      }
      if (num >= maxnum)
        break;
      right--;
      for (int i = right; i >= left; i--)
      {
        res[num++] = matrix[bottom][i];
        if (num >= maxnum)
          break;
      }
      if (num >= maxnum)
        break;
      bottom--;
      for (int i = bottom; i >= top; i--)
      {
        res[num++] = matrix[i][left];
        if (num >= maxnum)
          break;
      }
      if (num >= maxnum)
        break;
      left++;
    }
    return res;
  }
};
int main()
{
  vector<vector<int>> givenMatrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  Solution sol;
  vector<int> res = sol.spiralOrder(givenMatrix);
  for (auto num : res)
  {
    cout << num << endl;
  }

  return 0;
}