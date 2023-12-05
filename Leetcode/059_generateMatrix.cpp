#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int maxnum = n * n, num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (num <= maxnum)
    {
      for (int i = left; i <= right; i++)
      {
        res[left][i] = num;
        num++;
      }
      top++;
      for (int i = top; i <= bottom; i++)
      {
        res[i][right] = num;
        num++;
      }
      right--;
      for (int i = right; i >= left; i--)
      {
        res[bottom][i] = num;
        num++;
      }
      bottom--;
      for (int i = bottom; i >= top; i--)
      {
        res[i][left] = num;
        num++;
      }
      left++;
    }
    return res;
  }
};

int main()
{
  return 0;
}